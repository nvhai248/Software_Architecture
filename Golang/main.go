package main

import "fmt"

type geometry interface {
	printGeo()
	calculatorPerimeter() float32
}

type circle struct {
	radius int
}

type polygon struct {
	edges []int
}

type rectangle struct {
	width  int
	height int
}

func (c *circle) printGeo() {
	fmt.Println("Circle")
}

func (p *polygon) printGeo() {
	fmt.Println("Polygon")
}

func (r *rectangle) printGeo() {
	fmt.Println("Rectangle")
}

func (c *circle) calculatorPerimeter() float32 {
	return 2 * 3.14 * float32(c.radius)
}

func (p *polygon) calculatorPerimeter() float32 {
	result := 0
	for i := range p.edges {
		result += p.edges[i]
	}
	return float32(result)
}

func (r *rectangle) calculatorPerimeter() float32 {
	return (float32(r.height) + float32(r.width)) * 2
}

// Setter methods for each type
func (c *circle) setRadius(radius int) {
	c.radius = radius
}

func (p *polygon) setEdges(edges []int) {
	p.edges = edges
}

func (r *rectangle) setDimensions(width, height int) {
	r.width = width
	r.height = height
}

type FactoryGeo interface {
	PrintInformation() geometry
}

type FactoryCircle struct {
}

type FactoryRectangle struct {
}

type FactoryPolygon struct {
}

func (fc *FactoryCircle) PrintInformation() geometry {
	return &circle{}
}

func (fr *FactoryRectangle) PrintInformation() geometry {
	return &rectangle{}
}

func (fp *FactoryPolygon) PrintInformation() geometry {
	return &polygon{}
}

func main() {
	fmt.Println("Starting")

	// Example usage of the factory pattern
	circleFactory := &FactoryCircle{}
	circleGeo := circleFactory.PrintInformation()

	// Set values for circle
	circleGeo.(*circle).setRadius(5)

	circleGeo.printGeo()
	fmt.Printf("Perimeter: %f\n", circleGeo.calculatorPerimeter())

	// Example usage for rectangle
	rectangleFactory := &FactoryRectangle{}
	rectangleGeo := rectangleFactory.PrintInformation()

	// Set values for rectangle
	rectangleGeo.(*rectangle).setDimensions(3, 4)

	rectangleGeo.printGeo()
	fmt.Printf("Perimeter: %f\n", rectangleGeo.calculatorPerimeter())
}
