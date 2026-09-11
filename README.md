# Passforge

A password/passphrase generator and strength checker, reworked from the original C++ console version into an interactive, animated web app.

Everything runs client-side in `index.html` — no server, no build step, no dependencies except Google Fonts.

## Publish it on GitHub Pages

1. Create a new GitHub repository (or use an existing one).
2. Add `index.html` to the root of the repo (this file's name matters — GitHub Pages looks for `index.html`).
3. Commit and push.
4. In the repo, go to **Settings → Pages**.
5. Under "Build and deployment", set **Source** to "Deploy from a branch", pick your branch (usually `main`) and the `/ (root)` folder, then save.
6. GitHub will give you a URL like `https://yourusername.github.io/your-repo-name/` within a minute or two.

That's it — no npm install, no framework, nothing to build.

## What's different from the original C++ version

- **Password generator**: same idea (pick from uppercase/lowercase/digits/symbols, choose a length), but now uses `crypto.getRandomValues` for randomness instead of a seeded PRNG, and lets you toggle character sets on and off live.
- **Passphrase generator**: same leetspeak-style substitution concept (a→@, e→3, i→1, o→0, s→$), extended with more substitution options and randomized per-character choices so two runs of the same phrase don't look identical.
- **Strength checker**: rewritten from scratch — the original had a bug (`upperCase[c]` etc. treated array-indexing as a lookup, which isn't valid). The new version calculates actual entropy in bits, flags common weak passwords, repeated characters, and sequential runs (`abc`, `123`), and estimates realistic crack times for both online and offline attacks.
- **Education layer**: expandable "how this works" sections explain entropy, why length beats complexity, and how the passphrase tempering works — new relative to the original, which had no explanatory content.
- **Visual theme**: a blacksmith's forge metaphor — password strength is shown as heat, from a dull ember (weak) to white-hot (very strong), with small animations when you generate or test a password.

## Notes

- No password you type is transmitted anywhere — open the page source or your browser's network tab at any time to verify.
- The character-substitution map and common-password list are intentionally small and readable in the source if you want to extend them.
