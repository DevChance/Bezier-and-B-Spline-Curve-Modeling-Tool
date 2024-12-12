/*
 * Author: Chance Spurlin

 * Project: Interactive Spline Curve Renderer
 * 
 * Description: This project is an interactive tool for creating and visualizing spline curves, such as Bezier and B-splines.
 * It allows users to add, edit, and manipulate control points dynamically to see how curves are constructed and change in real time.
 * By implementing techniques like the de Casteljau algorithm and recursive subdivision, this project highlights my understanding of computational geometry
 * and rendering principles. Built from the ground up, it emphasizes efficient algorithms, clean design, and interactivity.
 * Originally developed as part of University of California: San Diego's Computer Graphics course, it reflects skills in problem-solving, mathematics, and technical implementation.
 *
 * Sources used: UCSD CSE 167 course materials, lecture slides, discussion slides, and additional computational geometry research.
 */

#include "WorkingScene.h"

 // Handles mouse dragging to update the position of control points on the curve.
 // Normalizes the drag delta values and updates the active control point's position.
void WorkingScene::drag(int x, int y) {
	float newDX = (x - oldx); // Change in x from the last position
	float newDY = (y - oldy); // Change in y from the last position
	float normDX = (newDX / width); // Normalize x change by window width
	float normDY = (newDY / height); // Normalize y change by window height
	theOnlyCurve->moveActivePoint(normDX, -(normDY)); // Move the active point based on normalized deltas
	oldx = x; // Update old x position
	oldy = y; // Update old y position
	glutPostRedisplay(); // Trigger scene redraw
}

// Handles mouse clicks for adding and deleting control points.
// Left click adds a control point; right click deletes the closest control point.
void WorkingScene::mouse(int button, int state, int x, int y) {
	float normX = static_cast<float>(x) / width; // Normalize x-coordinate
	float normY = 1.0f - (static_cast<float>(y) / height); // Normalize y-coordinate

	if (theOnlyCurve && state == GLUT_DOWN) { // Check if the mouse button was pressed
		if (button == GLUT_LEFT_BUTTON) {
			theOnlyCurve->addPoint(normX, normY); // Add a new control point
		}
		if (button == GLUT_RIGHT_BUTTON) {
			theOnlyCurve->updateActivePoint(normX, normY); // Select the active point to delete
			theOnlyCurve->deleteActivePoint(); // Delete the active point
		}
	}
	oldx = x; // Update old x position
	oldy = y; // Update old y position
	glutPostRedisplay(); // Trigger scene redraw
}

#include "Bezier.h"

// Draws a Bezier curve using the de Casteljau algorithm.
// The curve is evaluated at "levelOfDetail" points and connected with line segments.
void Bezier::draw(int levelOfDetail) {
	connectTheDots(); // Draw control polygon for reference
	Pvector bezPoints; // Points that form the Bezier curve
	float t;
	float currLvl = (1.0f / static_cast<float>(levelOfDetail)); // Step size for t

	if (points.size() < 2) { // Ensure there are at least two points to form a curve
		return;
	}

	// Evaluate the Bezier curve at detail+1 points using the de Casteljau algorithm
	for (t = 0.0f; t - 1.0f <= 1e-6; t += (currLvl)) {
		Pvector currPList = points; // Copy of control points for iterative computation
		for (int j = 0; j < (points.size() - 1); j++) { // Levels of subdivision
			Pvector tempPList;
			for (int i = 0; i < (currPList.size() - 1); i++) {
				float newXPos = ((t * currPList[i].x) + ((1 - t) * currPList[i + 1].x)); // Linear interpolation for x
				float newYPos = ((t * currPList[i].y) + ((1 - t) * currPList[i + 1].y)); // Linear interpolation for y
				tempPList.push_back(Point(newXPos, newYPos));
			}
			currPList = tempPList; // Update point list for next level
		}
		bezPoints.push_back(currPList.front()); // Add the final computed point to the curve
	}

	// Connect the computed points with line segments
	for (int k = 0; k < bezPoints.size() - 1; k++) {
		drawLine(bezPoints[k].x, bezPoints[k].y, bezPoints[k + 1].x, bezPoints[k + 1].y);
	}
}

#include "Bspline.h"

// Draws a B-spline curve using uniform cubic B-spline interpolation.
// Divides the control points into segments and draws each segment.
void Bspline::draw(int levelOfDetail) {
	connectTheDots(); // Draw control polygon for reference
	int currSize = points.size();
	int currRange = (currSize - 4); // Range of valid segments

	if (currSize < 4) { // Ensure there are enough points for a cubic B-spline
		return;
	}

	// Iterate through segments and draw each segment
	for (int i = 0; i <= currRange; i++) {
		drawSegment(points.begin() + i, points.begin() + (i + 1), points.begin() + (i + 2), points.begin() + (i + 3), levelOfDetail);
	}
}

// Draws a single segment of a B-spline curve using matrix multiplication.
void Bspline::drawSegment(Pvector::iterator p1, Pvector::iterator p2, Pvector::iterator p3, Pvector::iterator p4, int levelOfDetail) {
	float x = 0.0f, y = 0.0f;
	Point p(x, y), lastP(x, y);
	float matrixM[4][4] = { {-1.0f / 6.0f, 3.0f / 6.0f, -3.0f / 6.0f, 1.0f / 6.0f},
						  {3.0f / 6.0f, -6.0f / 6.0f, 3.0f / 6.0f, 0.0f},
						  {-3.0f / 6.0f, 0.0f, 3.0f / 6.0f, 0.0f},
						  {1.0f / 6.0f, 4.0f / 6.0f, 1.0f / 6.0f, 0.0f} };

	for (int i = 0; i <= levelOfDetail; i++) {
		float u = (i / static_cast<float>(levelOfDetail));
		float u3 = (u * u * u), u2 = (u * u), u1 = u;
		float Uvec4[4] = { u3, u2, u1, 1 }; // Basis vector for matrix multiplication

		float tempVec[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
		for (int currY = 0; currY < 4; ++currY) {
			for (int currX = 0; currX < 4; ++currX) {
				tempVec[currY] += Uvec4[currX] * matrixM[currX][currY];
			}
		}
		x = ((tempVec[0] * p1->x) + (tempVec[1] * p2->x) + (tempVec[2] * p3->x) + (tempVec[3] * p4->x));
		y = ((tempVec[0] * p1->y) + (tempVec[1] * p2->y) + (tempVec[2] * p3->y) + (tempVec[3] * p4->y));

		if (i > 0) {
			drawLine(p.x, p.y, x, y); // Connect the current point to the last point
		}

		p.x = x; p.y = y; // Update the last drawn point
		lastP.x = x; lastP.y = y; // Save the last point for knot visualization
	}
	lastP.draw(); // Draw the final point as a knot
}

#include "Bezier2.h"

// Accumulates intermediate control points for the next level of detail.
void accumulateNextLevel(Pvector* accum, Pvector pts) {
	if (pts.empty()) return; // Base case: no points left to process
	accum->push_back(*(pts.begin())); // Add the first point
	if (pts.size() == 1) return; // Base case: single point remains

	for (Pvector::iterator it = pts.begin(); it != pts.end() - 1; it++) {
		Point currMidPoint(((it->x + (it + 1)->x) / 2.0f), ((it->y + (it + 1)->y) / 2.0f)); // Midpoint calculation
		*it = currMidPoint; // Replace with midpoint
	}
	Point last = *(pts.end() - 1); // Save the last point
	pts.pop_back(); // Remove the last point
	accumulateNextLevel(accum, pts); // Recursive call to process the reduced set of points
	accum->push_back(last); // Add the saved last point
}

// Draws a Bezier curve using recursive subdivision.
// LevelOfDetail determines the recursion depth.
void Bezier2::draw(int levelOfDetail) {
	if (levelOfDetail > 0) {
		connectTheDots(); // Draw control polygon for reference in the top-level call
	}
	else {
		levelOfDetail = -levelOfDetail; // Flip negative recursion depth to positive
	}

	if (levelOfDetail <= 1) { // Base case: draw straight lines between control points
		if (points.size() >= 2) {
			for (Pvector::iterator it = points.begin(); it != points.end() - 1; it++) {
				drawLine(it->x, it->y, (it + 1)->x, (it + 1)->y);
			}
		}
	}
	else {
		Pvector* accum = new Pvector(); // Container for intermediate points
		Bezier2 left, right; // Subdivision into left and right Bezier curves
		accumulateNextLevel(accum, points); // Populate intermediate points

		for (int i = 0; i < accum->size(); i++) {
			Pvector::iterator accumP = (accum->begin() + i);
			if (i <= accum->size() / 2) {
				left.addPoint(accumP->x, accumP->y); // Points for left curve
			}
			if (i >= accum->size() / 2) {
				right.addPoint(accumP->x, accumP->y); // Points for right curve
			}
		}
		left.draw(1 - levelOfDetail); // Recursive call for left curve
		right.draw(1 - levelOfDetail); // Recursive call for right curve
		delete accum; // Clean up dynamically allocated memory
	}
}
