package main

import "fmt"

type geometry interface {
	initGeo() error
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

func main() {
	fmt.Println("Starting")
}
