/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-05-05
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description:\\
\begin{minipage}{75mm}
If a unique intersection point of the lines going through s1,e1 and s2,e2 exists \{1, point\} is returned.
If no intersection point exists \{0, (0,0)\} is returned and if infinitely many exists \{-1, (0,0)\} is returned.
The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
Products of three coordinates are used in intermediate steps so watch out for overflow if using int or ll.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{content/geometry/lineIntersection}
\end{minipage}
 * Usage:
 * 	auto res = lineInter(s1,e1,s2,e2);
 * 	if (res.first == 1)
 * 		cout << "intersection point at " << res.second << endl;
 * Status: stress-tested, and tested through half-plane tests
 */
#pragma once

#include "Point.h"

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}
template<class P, class Line>
P intersect(const Line &other) const {
  auto a1 = a, b1 = b, c1 = c,
    a2 = other.a, b2 = other.b, c2 = other.c;
  auto det = a2 * b1 - a1 * b2;
  // if det == 0 then no intersection, not handled yet
  auto x = (b2 * c1 - b1 * c2) / det;
  auto y = (a1 * c2 - a2 * c1) / det;
  return {x, y};
}
template<Line>
bool parallel(const Line &line) const {
  return a * line.b == b * line.a; }
template<Line>
Line perpendicular(const Point &p) const {
  return {-b, a, b * p.x - a * p.y}; }