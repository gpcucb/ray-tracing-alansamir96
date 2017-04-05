require_relative 'renderer.rb'
require_relative 'camera.rb'
require_relative 'vector.rb'
require_relative 'rgb.rb'
require_relative 'intersection.rb'
require_relative 'sphere.rb'
require_relative 'triangle.rb'
require_relative 'light.rb'
require_relative 'material.rb'

class RayTracer < Renderer

  attr_accessor :camera

  def initialize(width, height)
    super(width, height, 250.0, 250.0, 250.0)

    @nx = @width
    @ny = @height
    # Camera values
    e= Vector.new(278,273,-800)
    center= Vector.new(278,273,-700)
    #e= Vector.new(0,0,-800)
    #center= Vector.new(0,0,-700)
    up= Vector.new(0,1,0)
    fov= 39.31
    df=0.035
    @camera = Camera.new(e, center, up, fov, df)

    light_color = Rgb.new(0.8,0.7,0.6)
    light_position = Vector.new(500.0, 1000.0, 0.0)
    @light = Light.new(light_position,light_color)

    # Sphere values
    position = Vector.new(570,320,-100)
    radius = 120
    sphere_diffuse = Rgb.new(1.0, 0.0, 1.0)
    sphere_specular =Rgb.new(1.0,1.0,1.0)
    sphere_reflection = 0.5
    sphere_power = 60
    sphere_material = Material.new(sphere_diffuse, sphere_reflection, sphere_specular, sphere_power)

    #Sphere2 values
    position2 = Vector.new(300,200,0)
    radius2 = 120
    sphere_diffuse2 = Rgb.new(1.0, 0.0, 1.0)
    sphere_specular2 =Rgb.new(1.0,1.0,1.0)
    sphere_reflection2 = 0.5
    sphere_power2 = 60
    sphere_material2 = Material.new(sphere_diffuse2, sphere_reflection2, sphere_specular2, sphere_power2)

    # Triangle values
    a = Vector.new(0,0,0) #552,8,0
    b = Vector.new(500,0,0) #0,0,0
    c = Vector.new(0,500,500) #0,0,560
    triangle_diffuse = Rgb.new(0.0,0.4,0.0)
    triangle_specular = Rgb.new(1.0,1.0,1.0)
    triangle_reflection = 0.5
    triangle_power = 60
    triangle_material = Material.new(triangle_diffuse, triangle_reflection, triangle_specular, triangle_power)

    # Triangle2 values
    a1 = Vector.new(500,0,0) #552,8,0
    b1 = Vector.new(0,500,500) #0,0,0
    c1 = Vector.new(500,500,500) #0,0,560
    triangle_diffuse1 = Rgb.new(0.0,0.4,0.0)
    triangle_specular1 = Rgb.new(1.0,1.0,1.0)
    triangle_reflection1 = 0.5
    triangle_power1 = 60
    triangle_material1 = Material.new(triangle_diffuse1, triangle_reflection1, triangle_specular1, triangle_power1)

    @sphere = Sphere.new(position, radius, sphere_material)
    @sphere2 = Sphere.new(position2, radius2, sphere_material2)
    @triangle = Triangle.new(a, b, c, triangle_material)
    @triangle2 = Triangle.new(a1,b1,c1,triangle_material1)
    @objects=[]
    @objects << @sphere << @sphere2 << @triangle << @triangle2
  end

  def max(a_number,another_number)
    if a_number > another_number
      return a_number
    else
      return another_number
    end
  end


  def lambertian_shading (intersection_point, intersection_normal, ray, light, object)
      n = intersection_normal.normalize
      l = light.position.minus(intersection_point).normalize

      #nl = fix_color(n.scalar_product(l))
      nl = n.scalar_product(l)
      max = max(0,nl)
      kd = object.material.diffuse
      kdI = kd.multiply_color(light.color)
      return kdI.times_color(max)
  end

  def blinnPhong_shading(intersection_point, intersection_normal, ray, light, object)
    n = intersection_normal.normalize
    v = ray.position.minus(intersection_point).normalize
    l = light.position.minus(intersection_point).normalize
    h = v.plus(l).normalize

    #nh = fix_color(n.scalar_product(h))
    nh = n.scalar_product(h)
    ks = object.material.specular
    power = object.material.power
    max = max(0,nh)
    ksI = ks.multiply_color(light.color)

    return ksI.times_color(max**power)

  end

  def calculate_pixel(i, j)
    e = @camera.e
    dir = @camera.ray_direction(i,j,@nx,@ny)
    ray = Ray.new(e, dir)
    t = Float::INFINITY

    @obj_int = nil#intersected object
    @objects.each do |obj|
      intersection = obj.intersection?(ray, t)
      if intersection.successful?
        @obj_int = obj
        t = intersection.t
      end
    end
    if @obj_int==nil
      color = Rgb.new(0.0,0.0,0.0)
    else
      intersection_point = ray.position.plus(ray.direction.num_product(t)) #ray definition
      intersection_normal = @obj_int.normal(intersection_point)

      lambert = lambertian_shading(intersection_point,intersection_normal,ray,@light,@obj_int)
      blinn_phong = blinnPhong_shading(intersection_point,intersection_normal,ray,@light, @obj_int)
      puts "lambert r:#{lambert.r} g:#{lambert.g} b:#{lambert.b}"

      #color = @obj_int.material.diffuse #2D
      #color = lambert
      #color = lambert.add_color(blinn_phong)

      ka = @obj_int.material.diffuse
      #@ambient_light = Rgb.new(0.8,0.9,0.9)
      @ambient_light = Rgb.new(0.2,0.5,0.1)

      color = lambert.add_color(blinn_phong).add_color(@ambient_light.multiply_color(ka))

    end

    return {red: color.r, green: color.g, blue: color.b}
  end
end
