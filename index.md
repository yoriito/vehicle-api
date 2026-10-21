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


<details markdown="1">
<summary><b>Yoriito Vehicle API Reference (v0.1.0)</b></summary>

## Modules

| Module | Description |
|--------|-------------|
|[common](prev/0.1.0/html/common/index.html)| The Common Components like logger, databroker client, etc. |
|[signal](prev/0.1.0/html/signal/index.html)| The Signal level API of the Yoriito Vehicle API. |

</details>

