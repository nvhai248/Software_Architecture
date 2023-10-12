#include <iostream>
using namespace std;

class Geometry {
public:
    virtual std::string Notification() {
        return "";
    };

    virtual void printPerimeter() {
        return;
    }

    virtual ~Geometry() {} // Virtual destructor for proper cleanup
};

class Circle : public Geometry {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    std::string Notification() override {
        return "Circle";
    }

    void printPerimeter() override {
        cout << "Perimeter: " << 2 * 3.14 * radius << endl;
    }
};

class Polygon : public Geometry {
private:
    int* edges;
    int n;

public:
    Polygon(int* edgeArray, int numberOfEdges) : n(numberOfEdges) {
        edges = new int[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = edgeArray[i];
        }
    }

    std::string Notification() override {
        return "Polygon";
    }

    void printPerimeter() override {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += edges[i];
        }
        cout << "Perimeter: " << sum << endl;
    }

    ~Polygon() {
        delete[] edges; // Cleanup dynamically allocated memory
    }
};

class Rectangle : public Geometry {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    std::string Notification() override {
        return "Rectangle";
    }

    void printPerimeter() override {
        cout << "Perimeter: " << 2 * (width + height) << endl;
    }
};

class Factory {
public:
    virtual Geometry* createGeo() = 0;
};

class FactoryCircle : public Factory {
public:
    Geometry* createGeo() override {
        int radius;
        cout << "Enter radius for Circle: ";
        cin >> radius;
        return new Circle(radius);
    }
};

class FactoryPolygon : public Factory {
public:
    Geometry* createGeo() override {
        int n;
        cout << "Enter number of edges for Polygon: ";
        cin >> n;
        int* edges = new int[n];
        cout << "Enter the length of each edge:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Edge " << i + 1 << ": ";
            cin >> edges[i];
        }
        return new Polygon(edges, n);
    }
};

class FactoryRectangle : public Factory {
public:
    Geometry* createGeo() override {
        int width, height;
        cout << "Enter width for Rectangle: ";
        cin >> width;
        cout << "Enter height for Rectangle: ";
        cin >> height;
        return new Rectangle(width, height);
    }
};

int main() {
    std::string s = "";
    
    Factory* CircleFactory = new FactoryCircle();
    Geometry* Circle = CircleFactory->createGeo();
    s = Circle->Notification();
    std::cout << "Shape: " << s << endl;
    Circle->printPerimeter();
    delete Circle;
    
    Factory* PolygonFactory = new FactoryPolygon();
    Geometry* Polygon = PolygonFactory->createGeo();
    s = Polygon->Notification();
    std::cout << "Shape: " << s << endl;
    Polygon->printPerimeter();
    delete Polygon;
    
    Factory* RectangleFactory = new FactoryRectangle();
    Geometry* Rectangle = RectangleFactory->createGeo();
    s = Rectangle->Notification();
    std::cout << "Shape: " << s << endl;
    Rectangle->printPerimeter();
    delete Rectangle;
    
    delete CircleFactory;
    delete PolygonFactory;
    delete RectangleFactory;

    return 0;
}
