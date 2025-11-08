# Task 1: Parameter Testing and documentation of impact

---

## Goal
Explore how different parameters in `Constants.h` affect the N-body gravity simulation behavior.

---

## Parameters used for testing

1. **NUM_BODIES** - Number of particles in the disk
2. **SYSTEM_SIZE_AU** - View radius (zoom level) in Astronomical Units
3. **DISK_MASS_FRAC** - Fraction of total mass in the disk (vs central star)

---

## Default Parameters

### Parameter values:
```
#define NUM_BODIES      (10*1024)    // 10,240 bodies
#define SYSTEM_SIZE_AU  10.0         // 10 AU view radius
#define DISK_MASS_FRAC  0.2          // 20% mass in disk
```

### Observations:
- **Appearance:** Clear spiral disk pattern with clear individual particles
- **Particles:** Dense in center and gradually spreads out toward edges
- **Total Bodies:** 10,240 disk particles + 1 central star
- **Simulation Performance:** Completed 100 steps in roughly 29 seconds
---
### Screenshot:
- Frame 0 shows initial disk configuration
  - Using frame 0 for accuracy before simulation makes any particle changes

<img src="/Parameter_Testing/default_test_frame_0.png" alt="Test 1 image" width="400">


## Test 1: increasing NUM_BODIES

In this test, the number of bodies was increased by 2.5.

### Hypothesis (Before Running):
- The simulation will appear crowded because more particles are present
- It will take longer to run due to increased amount of computations
- Increased visual density

### Settings:
```
#define NUM_BODIES      (25*1024)    // 25,600 bodies (x2.5)
#define SYSTEM_SIZE_AU  10.0         // Default
#define DISK_MASS_FRAC  0.2          // Default
```

### Findings:
- **Appearance:** Significantly denser disc, much harder to see individual particles
- **Particles:** Much denser at the center (Yellow zone) and the outer areas are much more crowded than default
- **Total Bodies:** 25,600 disk particles + 1 central star
- **Simulation Performance:** Completed 100 steps in roughly a minute but still manageable due to the Barnes-Hut algorithm.

### Screenshot:

- Using frame 0

<img src="/Parameter_Testing/test1_frame_0.png" alt="Test 1 image" width="400">

### Conclusion:

Increasing ```NUM_BODIES``` directly increases visual density. The simulation handles the increased load fairly well due to the Barnes-Hut algorithm which scales as O(n log n) rather than O(n²).


---

## Test 2: Zooming In (Reducing SYSTEM_SIZE_AU)

### Hypothesis:

### Settings:

### Findings:

### Conclusion:

---

## Test 3: Increasing Disk Mass (DISK_MASS_FRAC)

### Hypothesis:

### Settings:

### Findings:

### Conclusion:


## Color Modifications

Instead of the default blue particles, I added 4 colour gradients to the render using 3 blending ranges. **(red -> yellow, yellow -> cyan and cyan -> blue)** This makes it look more appealing and helps you refer to different parts of the disc more clearly.

The colour is calculated dynamically based on each particle's distance from center star:

```
double dist = std::sqrt(rx * rx + ry * ry);
double normalized_dist = std::min(1.0, dist / view_half);
```


