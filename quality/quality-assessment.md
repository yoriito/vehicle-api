# Quality Assessment

## vehicle-api v0.2.0
### Signal API
All target items passed. See below for details.

| Category | Result | Reference |
| :------------------ | :-------------- | :------------------ |
| Unit Test | All 17,067 normal and 23,205 abnormal test cases passed. | [unit_test](./assets/unit-test-results.zip) |
| Coding Style (C++) | Checked by cpplint. Findings related to header file includes remain unresolved. | [coding_style](./assets/cpplint-result.zip) |
| Coding Metrics (C++) | Checked by lizard. No critical issue found. | [coding_metrics](./assets/lizard-result.zip) |
| Static Analysis (C++) | Checked by Coverity. No critical issue found. | [sast_vehicle-api](./assets/sast_vehicle-api.zip) |
| Dynamic Analysis (C++) | Fuzzing tests are performed using AFL++. AddressSanitizer is not enabled. No crashes found. | [dast_vehicle-api](./assets/dast_vehicle-api.log) |
| SCA | The SCA analysis was unable to properly detect C++ dependencies. | [SCA_report](./assets/SCA.pdf) |
| SBOM (C++) | The SBOM is not included in this release as the C++ dependencies could not be detected properly. | - |

### Logger
All target items passed. See below for details.

| Category | Result | Reference |
| :------------------ | :-------------- | :----- |
| Unit Test | Successful DLT logging <br> [build option: ENABLE_LOG_BACKEND_DLT = ON]   | [unit-test-logger_dlt](./assets/unit-test-logger_dlt-result.txt) |
|           | Successful stdout logging <br> [build option: ENABLE_LOG_BACKEND_DLT = OFF]   | [unit-test-logger_stdout](./assets/unit-test-logger_stdout-result.txt) |
| Coding Style (C++) | Checked by cpplint. Findings related to header file includes remain unresolved. | [coding_style](./assets/cpplint-result.zip) |
| Coding Metrics (C++) | Checked by lizard. No critical issue found. | [coding_metrics](./assets/lizard-result.zip) |
| Static Analysis (C++) | Checked by Coverity. No critical issue found. | [sast_vehicle-api](./assets/sast_vehicle-api.zip) |
