Hi HN,

I’ve been working for several years on xtd, a modern C++ framework inspired by .NET, with the goal of bringing the productivity of .NET development into native C++.

Why I built it:
	•	Existing C++ frameworks (like Qt, wxWidgets) often require heavy boilerplate, dynamic allocation, or aren’t consistent across platforms.
	•	.NET has a rich, unified class library and GUI toolkit. I wanted something similar for C++ developers who prefer RAII and modern C++ idioms.
	•	I enjoy pushing C++ to its limits — xtd is a way for me to learn, experiment, and share.

What xtd offers today:
	•	A full standard-like library (xtd.core) with additional utilities.
	•	GUI programming (xtd.forms) with a .NET-like API (buttons, forms, dialogs…).
	•	Drawing/graphics (xtd.drawing) abstraction layer.
	•	Unit testing (xtd.tunit) compatible with gtest.
	•	Cross-platform support: Windows, macOS, Linux, FreeBSD, Android, iOS, Haiku.

What makes it different:
	•	Designed to be usable with stack-allocated objects (no mandatory new everywhere).
	•	Consistent API modeled after .NET, but idiomatic modern C++.
	•	Extensible backends (drawing/forms can swap underlying APIs).
	•	Actively developed and fully open source (MIT).

I’d love feedback on:
	•	API design choices (too close to .NET? too far?).
	•	What’s missing for it to be useful in real projects.
	•	Ideas for future improvements, or pitfalls I should avoid.

Repo : https://github.com/gammasoft71/xtd
Website: https://gammasoft71.github.io/xtd/
Reference guide : https://gammasoft71.github.io/xtd/reference_guides/latest/index.html

Thanks for reading! Happy to answer any questions or criticism.
