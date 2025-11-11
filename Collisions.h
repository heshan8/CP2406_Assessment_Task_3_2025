#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include <cmath>
#include "Types.h"
#include "Constants.h"

// Merge b into a when distance(a,b) < thresholdAU.
// Conserves mass and linear momentum. Positions in AU; velocities in m/s.
// TODO Complete this function ...
inline void checkAndMergeCollision(body& a, body& b, double thresholdAU = COLLISION_THRESHOLD_AU) {
    double dx = a.position.x - b.position.x; // Difference in x positions between the two bodies (Horizontal)
    double dy = a.position.y - b.position.y; // Difference in y positions (Vertical)
    double dz = a.position.z - b.position.z; // Difference in z positions (Depth)
    double distance = sqrt(dx * dx + dy * dy + dz * dz); // Straight line distance (in 3D space)


/*
    If distance is less than thresholdDistance:
        Merge B into A:
        - Compute total mass = A.mass + B.mass
        - Update A.position to center of mass:
            A.position = (A.position * A.mass + B.position *
    B.mass) / total mass
        - Update A.velocity to conserve momentum:
            A.velocity = (A.velocity * A.mass + B.velocity *
    B.mass) / total mass
        - Set A.mass = total mass
        - Mark B as inactive (e.g., set B.velocity = 0)
*/

}

// Quadratic pass: merges any pairs closer than threshold; skips retired bodies.
template <typename Bodies>
inline void mergeAllCollisions(Bodies& bodies, double thresholdAU = COLLISION_THRESHOLD_AU) {
    const int n = static_cast<int>(bodies.size());
   /*
    for (int i = 0; i < n; ++i) {
        if (bodies[i].mass <= 0.0) continue;
        for (int j = i + 1; j < n; ++j) {
            if (bodies[j].mass <= 0.0) continue;
            checkAndMergeCollision(bodies[i], bodies[j], thresholdAU);
        }
    }
    */


    // TODO make this function faster by using random number generator ...


}

#endif // COLLISIONS_H