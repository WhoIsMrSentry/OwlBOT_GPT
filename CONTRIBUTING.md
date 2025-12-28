# Contributing to OwlBOT_GPT

Thank you for your interest in contributing to OwlBOT_GPT. This project contains example sketches and resources for ESP32 speech and ChatGPT integrations. To keep the repository useful and maintainable, please follow these guidelines.

## How to contribute

- Fork the repository and create a branch for your change (small, focused branches preferred).
- Open a pull request with a clear description of the change and the motivation.
- If your change adds or modifies a sketch, include a short `README.md` in the example folder explaining usage and dependencies.

## Pull request size and scope

- Prefer small, single-purpose PRs (bug fix, single example, documentation update).
- Large additions (many sketches or large binaries) should be proposed first via an issue and submitted as one or several smaller PRs.

## Code and file guidelines

- Do not commit secrets (API keys, Wi‑Fi passwords). Use `network_param.example.h` for examples and add real configs to `.gitignore`.
- Keep Arduino/ESP32-specific code in example folders. Each example should compile on its own or include build instructions.

## Testing

- If possible, verify compilation locally (Arduino IDE or PlatformIO) before opening a PR.
- Include logs or screenshots in the PR description when reporting runtime issues.

## Issue reporting

- Use the bug report template and include: board model, sketch path, steps to reproduce, and serial logs.

## License

By contributing you agree that your contributions will be licensed under the repository's license. See the `LICENSE` file for details.
