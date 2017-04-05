require_relative 'renderer.rb'
require_relative 'camera.rb'
require_relative 'vector.rb'
require_relative 'rgb.rb'
require_relative 'intersection.rb'
require_relative 'sphere.rb'
require_relative 'triangle.rb'

class RayTracer < Renderer

  attr_accessor :camera

  def initialize(width, height)
    super(width, height, 250.0, 250.0, 250.0)

    @nx = @width
    @ny = @height
    # Camera values
    e= Vector.new(278,273,-800)
    center= Vector.new(278,273,-700)
    up= Vector.new(0,1,0)
    fov= 39.31
    df=0.035
    @camera = Camera.new(e, center, up, fov, df)

    # Sphere values
    position = Vector.new(370,120,370)
    radius = 120
    sphere_color = Rgb.new(1.0,0.0,1.0)

    # Triangle values
    a = Vector.new(552,8,0)
    b = Vector.new(0,0,0)
    c = Vector.new(0,0,560)
    triangle_color = Rgb.new(1.0,1.0,0.0)

    @sphere = Sphere.new(position, radius, sphere_color)
    @triangle = Triangle.new(a, b, c, triangle_color)
    @objects=[]
    @objects << @sphere << @triangle
  end

  def calculate_pixel(i, j)
    e = @camera.e
    dir = @camera.ray_direction(i,j,@nx,@ny)
    ray = Ray.new(e, dir)
    t = Float::INFINITY

    @obj_int = nil
    @objects.each do |obj|
      intersection = obj.intersection?(ray, t)
      if intersection.successful?
        @obj_int = obj
      end
    end
    if @obj_int==nil
      color = Rgb.new(0.0,0.0,0.0)
    else
      color = @obj_int.material.difuse
    end

    return {red: color.r, green: color.g, blue: color.b}
  end
end