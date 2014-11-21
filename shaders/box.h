#ifndef INCLUDED_BOX_H
#define INCLUDED_BOX_H

#include "sphere.h"

struct Box {
  vec3 lo, hi;
};

bool overlaps(Box a, Box b) {
  return all(lessThanEqual(a.lo,b.hi))
      && all(lessThanEqual(b.lo,b.hi));
}

Box bound(Box a, Box b) {
  return Box(min(a.lo,b.lo),max(a.hi,b.hi));
}

Box bound(Box a, vec3 b) {
  return Box(min(a.lo,b),max(a.hi,b));
}

vec3 position(Box a) {
  return (a.lo+a.hi)/2;
}

Sphere sphere(Box a) {
  return sphere(0.5*(a.lo+a.hi),0.5*length(a.hi-a.lo));
}

Box box(Sphere a) {
  vec3 d = vec3(a.s.w);
  return Box(a.s.xyz-d,a.s.xyz+d);
}

#endif