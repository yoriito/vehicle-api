# Fuzz Testing

All harnesses use AFL++. The AFL++ compiler backend is derived from `CMAKE_CXX_COMPILER`:

| `CMAKE_CXX_COMPILER` | Notes |
|---|---|
| `afl-g++` (default) | GCC plugin instrumentation |
| `afl-clang-fast++` | LTO instrumentation, faster feedback |

Run inside the DevContainer. `/work` is mounted to vehicle-api.

## Build Options

| Option | Default | Description |
|---|---|---|
| `ENABLE_FUZZ_TESTS` | `OFF` | Enable building fuzz test harnesses. |
| `ENABLE_ASAN` | `OFF` | Enable AddressSanitizer (includes LeakSanitizer). Detects memory errors such as buffer overflows, use-after-free, and memory leaks. |
| `ENABLE_UBSAN` | `OFF` | Enable UndefinedBehaviorSanitizer. Detects undefined behavior such as signed integer overflow, null pointer dereference, and invalid shifts. |
| `ENABLE_LOG_BACKEND_DLT` | `ON` | DLT logging backend. Set `OFF` for environments without libdlt (e.g. fuzz build containers). |

## Build and run with GCC (default)

```sh
mkdir -p /work/build_fuzz && cd /work/build_fuzz
cmake -DCMAKE_CXX_COMPILER=afl-g++ \
      -DENABLE_FUZZ_TESTS=ON \
      -DENABLE_ASAN=ON \
      -DENABLE_UBSAN=ON \
      -DENABLE_LOG_BACKEND_DLT=OFF \
      ..
make

/work/test_fuzz/run_fuzz_all.sh 60
```

## Build and run with Clang

```sh
mkdir -p /work/build_fuzz && cd /work/build_fuzz
cmake -DCMAKE_CXX_COMPILER=afl-clang-fast++ \
      -DENABLE_FUZZ_TESTS=ON \
      -DENABLE_ASAN=ON \
      -DENABLE_UBSAN=ON \
      -DENABLE_LOG_BACKEND_DLT=OFF \
      ..
make

/work/test_fuzz/run_fuzz_all.sh 60
```



A summary is printed when all harnesses finish:

```
=== Results ===
  FuzzGet_Float:  crashes=62, hangs=0
  FuzzGet_Double: crashes=58, hangs=0
  FuzzSet_Float:  crashes=41, hangs=0
  ...
```

Crash inputs are saved under `findings/<harness>/default/crashes/`.

## Running a Single Harness

```sh
mkdir -p /work/findings/FuzzGet_Float
afl-fuzz \
  -i /work/test_fuzz/corpus/float \
  -o /work/findings/FuzzGet_Float \
  -V 60 \
  -- /work/build_fuzz/test_fuzz/harness/FuzzGet_Float
```

## Reproducing a Crash

```sh
CRASH=$(ls /work/findings/FuzzGet_Float/default/crashes/id:* | head -1)
/work/build_fuzz/test_fuzz/harness/FuzzGet_Float < "${CRASH}"
echo "exit: $?"   # 134 (SIGABRT) = std::bad_variant_access detected
```

API documentation is published on [GitHub Pages](https://docs.yoriito.dev/).
