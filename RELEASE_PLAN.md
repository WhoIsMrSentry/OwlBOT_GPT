# Release plan and module split

Goal: avoid a single huge initial commit containing all example files. Instead, provide a minimal initial repo surface and add remaining examples in small, categorized releases or PRs.

Suggested steps:

1. Initial minimal release (v0.1):
   - `README.md`, `LICENSE`, `.gitignore`, `CONTRIBUTING.md`, PR/issue templates
   - 1–2 canonical examples (e.g., `Animatronic_Owl_Sample`, `ChatGPT_ESP32_DemoCode`)

2. Module releases (v0.2+): split remaining examples into modules and add each as a focused PR:
   - `speech-to-text` module (all speech-to-text examples and helpers)
   - `text-to-speech` module (TTS examples)
   - `hardware-examples` (animatronic and servo projects)
   - `tools` (shared code, model files)

3. CI and checks: add incremental CI that attempts to compile each module when its PR is opened.

4. Tagging and releases: use GitHub Releases for each module/stable snapshot.

Notes:
- Keep sensitive files out of the repo — provide `network_param.example.h` and request contributors to copy to `network_param.h`.
- Encourage small, compile-verified PRs.
