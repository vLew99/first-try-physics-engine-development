#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "types.h"
#include "collision.h"
#include "polygon_funcs.h"
#include "vector_funcs.h"
#include "dynamics.h"


// point to point collision testing
// void fun1() {
// 	Point2D a = {1.2223, 2.2};
// 	Point2D b = {1.2223, 2.2};
// 	Point2D c = {1.2223, 2.2};

// 	printf("Point A: (%f,%f)\n", a.x, a.y);
// 	printf("Point B: (%f,%f)\n", b.x, b.y);
// 	printf("Point C: (%f,%f)\n", c.x, c.y);

// 	printf("Are they colliding A B: %i\n", CheckPointPointCollision(&a, &b));
// 	printf("Are they colliding A C: %i\n", CheckPointPointCollision(&a, &c));
// 	printf("Are they colliding B C: %i\n", CheckPointPointCollision(&c, &b));
// }

// // point to circle collision testing
// void fun2() {
// 	Point2D a = {1, 2};


// 	Circle c = {4, 5, 4.25};
// 	Circle c2 = {4, 5, 4.22};

// 	printf("Point A: (%lf,%lf)\n", a.x, a.y);
// 	printf("Circle C: (%lf,%lf) - %lf\n", c.x, c.y, c.radius);
// 	printf("Circle C2: (%lf,%lf) - %lf\n", c2.x, c2.y, c2.radius);
// 	printf("Are they colliding: %i\n", CheckPointCircleCollision(&a, &c));
// 	printf("Are they colliding: %i\n", CheckPointCircleCollision(&a, &c2));
// }

// // circle to circle collision testing
// void fun3() {
// 	Circle c = { 0, 5, 4};
// 	Circle d = {10, 5, 6};
// 	Circle e = {10, 5, 5.999};

// 	printf("Circle C: (%lf,%lf) - %lf\n", c.center.x, c.center.y, c.radius);
// 	printf("Circle D: (%lf,%lf) - %lf\n", d.center.x, d.center.y, d.radius);
// 	printf("Circle E: (%lf,%lf) - %lf\n", e.x, e.y, e.radius);
// 	printf("Are they colliding: %i\n", CheckCircleCircleCollision(&c, &d));
// 	printf("Are they colliding: %i\n", CheckCircleCircleCollision(&c, &e));
// }

// // circle to line collision testing
// void fun4() {
// 	Circle c = {0, 0, 5};
// 	Line2D l = {7.071059 , 0, 0, 7.071059};

// 	printf("Circle C: (%lf,%lf) - %lf\n", c.center.x, c.center.y, c.radius);
// 	printf("Line L: (%lf,%lf) (%lf,%lf)\n", l.x1, l.y1, l.x2, l.y2);
// 	printf("Are they colliding: %i\n", CheckCircleLineCollision(&c, &l));
// }

// // point to triangle collision testing
// void fun5() {
// 	Point2D a = {5, 3};
// 	Triangle t = {1, 2, 6, 2, 5, 5};
// 	real_t error = 0.00001;
// 	printf("Is Point Collliding with triangle: %d\n", CheckPointTriangleCollision(&a, &t));
// }

// void fun6() {
// 	Circle c = {0, 0, 5};
// 	Rect2D r = {-2, -6, 2, -10};
// 	Rect2D r2 = {-6, 4, -4, 2};
// 	printf("Is Circle Colliding with Rect: %d\n", CheckCircleRectCollision(&c, &r));
// 	printf("Is Circle Colliding with Rect: %d\n", CheckCircleRectCollision(&c, &r2));

// }

// void fun7() {
// 	Vector2 a = {0, -2};
// 	real_t rad = atan2(a.y, a.x);
// 	printf("%f\n", rad);
// 	real_t deg = 180*rad/M_PI;
// 	printf("%f\n", deg);
// }

// void fun8() {
// 	Vector2 a = {1, 2};
// 	Vector2 b = {2, 1};
// 	Vector2* y = Add1(&a, &b);

// 	free(y);

// 	printf("%f - %f\n", y->x, y->y);
// 	Vector2 p1 = Add2(&a, &b);
// 	printf("%f - %f\n", p1.x, p1.y);

// 	Vector2 p2 = Subtract(&a, &b);
// 	printf("%f - %f\n", p2.x, p2.y);

// 	printf("Norm : %f\n", Norm(&p1));
// 	printf("Norm : %f\n", Norm(&p2));
// 	printf("Dot: %f\n", Dot(&p1, &p2));

// 	Vector2 u1 = Normalize(&p1);

// 	printf("Normalize: (%f, %f)\n", u1.x , u1.y);


// }

// void fun9() {
// 	Line2D a = {1, 2, 6, 2};
// 	Line2D b = {3, 5, 2, 5};

// 	printf("Are these lines colliding : %d\n", CheckLineLineCollision(&a.a, &a.b, &b.a, &b.b));
// }


// void fun10() {
// 	Rect2D r = {-1, 1, 1, -1};
// 	Line2D l = {-1.25, -1.25, -1.02, 1.02};
// 	Vector2 rp2 = {r.x2, r.y1};
// 	Vector2 rp4 = {r.x1, r.y2};
// 	printf("Are these rectangle and line colliding : %d\n", CheckRectLineCollision(&r.a, &rp2, &r.b, &rp4, &l.a, &l.b));

// }






int main() {


	// fun7();

	// fun1();
	// fun2();
	// fun3();
	// fun4();
	// fun5();
	// fun6();
	// 
	


	// int a = 50;
	// double value = *(double *)&a;

	// printf("%d , %lf", a, value);

	// struct Entity e = {5, 8};
	// int *x = (unsigned int*)&e;
	// printf("%p\n", *x);
	// printf("Sizeof struct Entity: %ld\n", sizeof(e));	
	// printf("%p\n", (&e));


	// Vector2 e1 = {10, 20};
	// printf("%f, %f\n", e1.x, e1.y);


	// Point2D e2 = {11, 22};
	// printf("%f, %f\n", e2.x, e2.y);

	// Rect2D r1 = {10, 20, 40, 40};
	// printf("(%f, %f) (%f, %f)\n", r1.x1, r1.y1, r1.x2, r1.y2);
	// printf("(%f, %f) (%f, %f)\n", r1.a.x, r1.a.y, r1.b.x, r1.b.y);


	// Circle cir = {0, 0, 5};
	// Vector2 temp = cir.c;

	// printf("(%f, %f) - %f\n", temp.x, temp.y, cir.r);

	// distance(e2);


	return 0;
}