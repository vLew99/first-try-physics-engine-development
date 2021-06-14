#ifndef TYPES_HEADER
#define TYPES_HEADER



#ifdef USE_DOUBLE
	typedef double real_t;
#else
	typedef float real_t;
#endif



typedef struct {
	real_t x, y;
} Vector2, Point2D;


typedef struct {
	union {
		struct { real_t x, y, z; }; 					// (x, y, z)
		struct { Vector2 center; real_t radius; };				// Vector2 c, real_t r
	};
} Vector3, Point3D, Circle;

typedef struct {
	union {
		// not implementing this because it will create amibiguity in the way that Rect is represented
		// i'm implementing Rect as top left corner and bottom right corner;
		// struct { real_t x, y, w, h;}; 					// x, y, w, h 
		struct { real_t x1, y1, x2, y2;};				// x1, y1, x2, y2
		struct { Vector2 a, b; };						// Vector2 a, Vector2 b
	};
} Vector4, Point4D, Line2D, Rect2D;


typedef struct {
	union {
		// same problem as above
		// struct { real_t x, y, z, w, h, d;};				// x, y, z, w, h, d
		struct { real_t x1, y1, z1, x2, y2, z2; };		// (x1, y1, z1)  (x2, y2, z2)
		struct { Vector3 a, b; };						// Vector3 a, Vector3 b
	};
} Line3D, Rect3D;


typedef struct {
	union {
		struct { real_t x1, y1, x2, y2, x3, y3; };
		struct { Vector2 a, b, c; };
	};
} Triangle;


typedef struct {
	unsigned int count;
	Point2D* points;
} Polygon2D;



#endif