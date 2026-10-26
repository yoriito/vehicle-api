# Yoriito Vehicle API

## Overview

Yoriito Vehicle API is the standard implementation of the vehicle signal API defined by JASPAR (Japan Automotive Software Platform and Architecture).

This repository provides a unified access method to vehicle data based on VSS (Vehicle Signal Specification). Application developers can retrieve and set various vehicle sensor and actuator data (speed, position, body status, powertrain, ADAS functions, etc.) through a standardized API. For details on Yoriito VSS definitions, please refer to the [Yoriito VSS vspec](https://github.com/yoriito/yoriito-vss).

### Key Use Cases

- **In-Vehicle Application Development**: Building applications that utilize vehicle signals
- **Simulation & Testing**: Testing in development environments that simulate vehicle data
- **Data Broker Integration**: Subscribing to and publishing signals via Yoriito Vehicle API

For detailed API reference, please refer to the [documentation](https://docs.yoriito.dev/apirefguide/).

## Getting Started

### Prerequisites

- CMake 3.28 or later
- C++ compiler (GCC or Clang)
- (Optional) ccache for faster rebuilds

We recommend using DevContainer as the development environment. Install the VS Code "Remote - Containers" extension and open this repository in DevContainer.

**Note**: DevContainer comes with all necessary dependencies pre-installed, including kura-client.

### Build Instructions

```bash
mkdir build && cd build
cmake ..
make
```

To install:

```bash
make install
```

#### Division Build
You can build only target Domain with the option.
- Valid Domain option name is the following:
  - ENABLE_POWERTRAIN
  - ENABLE_BODY
  - ENABLE_CABIN
  - ENABLE_ADAS
  - ENABLE_CHASSIS
  - ENABLE_DRIVER
  - ENABLE_OCCUPANT
  - ENABLE_EXTERIOR
  - ENABLE_VERSIONVSS
  - ENABLE_VEHICLEIDENTIFICATION
  - ENABLE_LOWVOLTAGEBATTERY
  - ENABLE_ACCELERATION
  - ENABLE_ANGULARVELOCITY
  - ENABLE_TRAILER
  - ENABLE_CURRENTLOCATION
  - ENABLE_VERSIONYORIITOVSS
  - ENABLE_MOTIONMANAGEMENT
  - ENABLE_CONTROLUNIT

For example, the following command build only BODY domain.
```bash
mkdir build && cd build
cmake -DENABLE_BODY=ON ..
make
```
**Note**: For build all the domain, no domain option is required. Without domain option, it is treated all the domain are enabled internally.

### Unit Test Build & Execution

Unit tests use Google Test.

```bash
mkdir build && cd build
cmake -DENABLE_TESTS=ON ..
make
ctest
```

**Note**: Unit tests require `BUILD_COMMON=ON` and `BUILD_SIGNAL=ON` (enabled by default).

#### Testing with Coverage Report

```bash
mkdir build && cd build
cmake -DENABLE_TESTS=ON -DCODE_COVERAGE=ON ..
make
ctest
# Generate coverage report (requires tools like gcovr)
```

## Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `BUILD_COMMON` | ON | Build common library (logger, etc.) |
| `BUILD_SIGNAL` | ON | Build signal API library |
| `ENABLE_DOCS` | OFF | Generate Doxygen documentation |
| `ENABLE_TESTS` | OFF | Build unit tests (requires BUILD_COMMON and BUILD_SIGNAL) |
| `CODE_COVERAGE` | OFF | Enable coverage reporting (GCC/Clang only) |
| `ENABLE_FUZZ_TESTS` | OFF | Build AFL++ fuzz harnesses (requires AFL++ compiler) |
| `ENABLE_LOG_BACKEND_DLT` | ON | Enable DLT log backend (set OFF for fuzz testing environments without libdlt) |

API documentation is published on [GitHub Pages](https://docs.yoriito.dev/).

## Commit Message Guidelines

This project follows [Conventional Commits](https://www.conventionalcommits.org/).

## Versioning

This project follows [Semantic Versioning](https://semver.org/).

The version is managed independently from the overall Yoriito version.

## Quality Assessment
 
This repository contains quality assessment results for this project.
Please refer to the [quality assessment page](./quality/quality-assessment.md).

The results are provided for transparency and reference purposes and do not constitute any warranty or guarantee of quality.

### Contents

 - Unit Test
- Coding Style
- Code Metrics
- Static Analysis
- Dynamic Analysis
- SCA
- SBOM

### Notes
 
Some files in this directory may be generated automatically by CI tools.
