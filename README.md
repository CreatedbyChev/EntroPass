# PROJECT OVERVIEW

EntroPass is a web-based, user interactive password manager that helps users create passwords or phrases that are easy for humans to remember and painfully hard for computers to guess. It measures strength the way attackers actually think about it: in bits of entropy, a unit of measure for randomness and cryptography. 

Users enter 3–5 everyday words, and EntroPass converts them into a secure, personalized passphrase using substitutions, symbol injection, entropy boosting, and optional hash‑like transformations.

Its purpose is to educate users on the importance of password security, while demonstrating the key components of a strong password/passphrase. 

## The Problem:
How many times have you heard someone say: "No one can guess my password..."  or "I thought my password was strong..."?

It always starts the same way. Someone proudly types in P@ssw0rd!23, convinced the symbols and numbers make them invincible. Meanwhile, a hacker cracks it in under a second, x2 faster than it takes to microwave popcorn.
Passwords fail because they’re short, predictable, and built on the myth that complexity equals security. Humans choose patterns while computers identify and break patterns. It’s an unfair fight.

And on the flip side, you have the other tragedy:

People create ridiculously complex passwords — T!m3sSqU@r3#19&* — something so chaotic even they can’t remember it or understand how secure it is. They forget it, reset it, forget the reset, reset it again, and eventually end up with a notebook full of scribbles or a phone note titled “PASSWORDS DO NOT OPEN.” In this case, complexity becomes its own enemy.


## The Solution:
EntroPass is built to end the password struggle once and for all. If weak passwords crack instantly and overly‑complex ones get forgotten just as fast, EntroPass steps in as the middle ground that actually works. It transforms simple, memorable passphrases into highly encoded passphrases that are both secure and human‑friendly.

Instead of forcing people to choose between “easy but unsafe” or “secure but impossible to remember,” EntroPass gives them a third option: strong, personalized, unforgettable security.

## Its Features:
- **Password generator**: same idea (pick from uppercase/lowercase/digits/symbols, choose a length), but now uses `crypto.getRandomValues` for randomness instead of a seeded PRNG, and lets you toggle character sets on and off live.
- **Passphrase generator**: same leetspeak-style substitution concept (a→@, e→3, i→1, o→0, s→$), extended with more substitution options and randomized per-character choices so two runs of the same phrase don't look identical.
- **Strength checker**: rewritten from scratch — the original had a bug (`upperCase[c]` etc. treated array-indexing as a lookup, which isn't valid). The new version calculates actual entropy in bits, flags common weak passwords, repeated characters, and sequential runs (`abc`, `123`), and estimates realistic crack times for both online and offline attacks.
- **Education layer**: expandable "how this works" sections explain entropy, why length beats complexity, and how the passphrase tempering works — new relative to the original, which had no explanatory content.
- **Visual theme**: a blacksmith's forge metaphor — password strength is shown as heat, from a dull ember (weak) to white-hot (very strong), with small animations when you generate or test a password.

## Features

- No password you type is transmitted anywhere — open the page source or your browser's network tab at any time to verify.
- The character-substitution map and common-password list are intentionally small and readable in the source if you want to extend them.
