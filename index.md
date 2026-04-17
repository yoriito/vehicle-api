---
title: "Yoriito Vehicle API Reference"
description: "API reference for the Yoriito Vehicle API"
---

# Yoriito Vehicle API Reference

## Modules

| Module | Description |
|--------|-------------|
|[common](html/common/index.html)| The Common Components like logger, databroker client, etc. |
|[signal](html/signal/index.html)| The Signal level API of the Yoriito Vehicle API. |

## How to generate the documentation

To generate the documentation only, run the following commands from the repository root:

```bash
cmake -S . -B build -DBUILD_COMMON=OFF -DBUILD_SIGNAL=OFF -DENABLE_DOCS=ON
cmake --build build --target docs
```
