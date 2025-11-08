# Task 1: Parameter Testing and documentation of impact

---

## Goal
Test three parameters in `Constants.h` using multiple values to see how they affect the N-body gravity simulation behavior.

## Parameters used for testing

1. ```NUM_BODIES``` - Number of particles in the disk
2. ```SYSTEM_SIZE_A``` - View radius (zoom level) in Astronomical Units
3. ```DISK_MASS_FRAC``` - Fraction of total mass in the disk (vs central star)

---

## Parameter 1: Number of disc particles ```NUM_BODIES```

### Values Tested:
1. ```#define NUM_BODIES  (10*1024)``` (10,240 bodies)
2. ```#define NUM_BODIES  (20*1024)``` (20,480 bodies)
3. ```#define NUM_BODIES  (30*1024)``` (30,720 bodies)

### Video Observations

#### 10,240 bodies (10*1024):
- Individual particles are clearly visible throughout the simulation
- Starts off with evenly spread particles
- Outer bodies start to form groups
- Smooth spiral slowly forms
- Dense in the center, gradually spread out toward the edges
- The Simulation was completed in roughly 16 seconds

#### 10,240 bodies (20*1024)
- Disk is now much denser with double the amount of bodies
- Individual particles are still somewhat distinguishable
- Starts off with evenly spread particles
- Slightly arger groups are forming due to increased bodies
- Center spiral is more distinguishable
- The Simulation was completed in roughly 50 seconds

#### 10,240 bodies (30*1024)
- Disk is now significantly denser with triple the amount of bodies
- Individual particles are difficult to make out and are lending together
- Much larger groups are forming around the edges
- Starts off resembling a solid disk 
- Center spiral is much more prominent showing clear arms
- The simulation was completed in toughly 2 minutes

#### Summary

Increasing ```NUM_BODIES``` directly increases particle density.The Barnes-Hut algorithm handles the increase body count fairly well, even with the progressively increasing runtimes. Higher particle counts create more realistic galactic density but makes it difficult to see individual particles clearly.

---

## Test 2: Reducing the system size ```SYSTEM_SIZE_AU```

In this test, the system size was reduced to 5.0 from 10.0 (Halved)

### Predictions:
- Fewer particles will appear due to the outer being cut off (Zoomed in)
- More detail on the particles that are visible
- The particles will look slightly bigger
- Shorter runtime

### Settings:

```
#define NUM_BODIES      (10*1024)   // 10,240 bodies (Default)
#define SYSTEM_SIZE_AU  5.0         // Halved form 10.0
#define DISK_MASS_FRAC  0.2         // Default
```

### Findings:
- **Appearance:** 
  - Prediction CONFIRMED - Individual particles appear larger
- **Particles:** 
  - Better detail in the center, but outer edges are cut off
  - Prediction CONFIRMED - Can clearly distinguish individual particles, especially in red area
  - Fewer particles visible in frame
- **Simulation Performance:** 
  - Completed 100 steps in roughly 16 seconds
  - Run time may be slightly shorter due to fewer visible particles being rendered

### Screenshot

- Test 02 Frame 0

<img src="/Parameter_Testing/test2_frame_0.png" alt="Test 1 image" width="400">

### Conclusion:
Reducing the system size ```SYSTEM_SIZE_AU``` zooms in on the simulation.
Particles appear bigger, more details visible in the center, but the outer edges of the disc are out of view.
This parameter is useful when you need to examine specific areas in the simulation more closely.

---

## Test 3: Increasing Disk Mass ```DISK_MASS_FRAC```
For this test, the mass of the disc was increased from 0.2 (20%) to 1.0 (100%)

### Predictions:
- Adding more mass could change the disk's orbit if the change is high enough
- Particles may interact more with each other or group together
- Less stable in the disk due to the central star having less gravitational control
- Run time should be close to default since the number of bodies is unchanged

### Settings:
```
#define NUM_BODIES      (10*1024)   // 10,240 bodies (Default)
#define SYSTEM_SIZE_AU  10.0        // Default
#define DISK_MASS_FRAC  0.8         // Chanaged from 0.2 (20%) to 1.0 (100%)
```

### Findings:
**Test 03 Frame 0:**
- Particle distribution is similar to frame 0 from the default test

**Test 03 Frame 100:**
- **Appearance:** 
  - Disk is much more spread out compared to frame 0
  - Distinct spiral pattern in the center
- **Particles:** 
  - Prediction CONFIRMED - More space between particles and clear grouping compared to Frame 0 and Default Frame 100
  - Prediction CONFIRMED - Clear particle orbit changes
- **Simulation Performance:** 
  - Completed 100 steps in roughly 16 seconds, which is similar to default test.

**Test 03 Frame 100 vs Default test Frame 100:**
- Default Test ```DISK_MASS_FRAC = 0.2```
  - Spiral pattern is present but less distinct
  - Less grouping 
- Test 3 ```DISK_MASS_FRAC = 1.0```
  - shows dispersed and chaotic distribution
  - Much tighter grouping (Brighter spots in the cyan region)
  - Distinct spiral pattern in the center (Lines visible in yellow section)
  - Central star has less control of the bodies

### Screenshot:

- The first two tests only show rendering differences. 
- DISK_MASS_FRAC affects the physics of the simulation. 
- Both (Frame 0) and (Frame 100) are used to show the progression of the bodies in the simulation."

#### Test 03 Frame 0:
<img src="/Parameter_Testing/test3_frame_0.png" alt="Test 3" width="400">

#### Test 03 Frame 100:

<img src="/Parameter_Testing/test3_frame_100.png" alt="Test 3" width="400">

#### Default Frame 100:

<img src="/Parameter_Testing/default_test_frame_100.png" alt="Test 3" width="400">

### Conclusion:
DISK_MASS_FRAC has a clear effect on system stability. When the disk mass gets closer to the mass of the central star, Particle interactions seem to increase causing much more random. This reduces disc stability where as the default creates a nice stable system with much more organized orbits.

## Color Modifications

Instead of the default blue particles, I added 4 colour gradients to the render using 3 blending ranges. **(red -> yellow, yellow -> cyan and cyan -> blue)** This makes it look more appealing and helps you refer to different parts of the disc more clearly.

The colour is calculated dynamically based on each particle's distance from center star:

```
double dist = std::sqrt(rx * rx + ry * ry);
double normalized_dist = std::min(1.0, dist / view_half);
```


