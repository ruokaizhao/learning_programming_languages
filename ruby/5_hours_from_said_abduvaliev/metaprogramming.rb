module Custom
  module Concern
    def self.included(base)
      base.extend ClassMethods
    end

    module ClassMethods
      def in_class(&block)
        @in_class_block = block
      end

      def class_methods(&block)
        @class_methods_block = block
      end

      def included(base)
        base.class_eval &@in_class_block
        base.instance_eval &@class_methods_block
      end
    end
  end
end

module MyModule
  include Custom::Concern

  def instance_method
    "instance method"
  end

  in_class do
    attr_accessor :foo
  end

  class_methods do
    def class_method
      "class method"
    end
  end

end

class MyClass
  include MyModule
end

puts MyClass.new.instance_method.inspect
puts MyClass.instance_methods(false).inspect
puts MyClass.class_method.inspect
