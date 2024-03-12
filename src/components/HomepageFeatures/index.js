import React from 'react';
import clsx from 'clsx';
import styles from './styles.module.css';

const FeatureList = [
  {
    description: (
      <>
      (*) See <a href="docs/documentation/portability#the-xtd-libraries-portability-list">portability</a> for more information.                                                                                                    <br/> 
      </>
    ),
  },
  {
    title: 'Latest news',
    description: (
      <>
      • <a href="docs/news/20240312">Release xtd 0.1.2 (beta) - March 12, 2024</a>
      <br/>• <a href="docs/news/20231112">The xtd 0.2.0 (beta) is growing - November 12, 2023</a>
      <br/>• <a href="docs/news/20230717">Release xtd 0.1.1 (beta) - Jully 17, 2023</a>
      <br/>• <a href="docs/news/20230209">The new xtd website is online - February 9, 2023</a>
      <br/>• <a href="docs/news">All news</a>
      </>
    ),
  },
  {
    title: 'Features',
    description: (
      <>
      • Free and open-source (<a href="docs/documentation/license">MIT License</a>).
      <br/>• A collection of native C++ classes libraries, to complete std.
      <br/>• API close to the .net API with modern C++ approach and full integration with the std standard.
      <br/>• xtd is designed to manage GUI controls and dialogs in pure <a href="docs/documentation/Guides/xtd.forms/Overview/control_appearance">native mode</a> or with <a href="docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">CSS styles</a>.
      <br/>• Written in efficient, modern <a href="https://en.cppreference.com/w/">c++17/20</a> with <a href="https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization">RAII</a> programming idiom.
      <br/>• And <a href="docs/documentation/portability">highly portable</a> and available on <a href="docs/documentation/portability">many different platforms</a> (Windows, macOS, Linux, iOS and android).
      <br/>• See <a href="docs/documentation/features">features</a> for more informations.
      </>
    ),
  },
  {
    title: 'xtd libraries architecture',
    description: (
      <>
      <a href="docs/documentation/Guides/Overview/Libraries/hierarchy"><img src="pictures/block_diagram_onion.png"/></a>
      <br/>xtd is composed of several libraries.
      <br/><br/><font size="+2">xtd.core</font>
      <br/><a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html"><img src="pictures/xtd.core.png"/></a> The <a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html">xtd.core</a> library is modern c++17/20 library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
      <br/><br/><font size="+2">xtd.drawing</font>
      <br/><a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html"><img src="pictures/xtd.drawing.png"/></a> The <a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__drawing.html">xtd.drawing</a> library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
      <br/><br/><font size="+2">xtd.forms</font>
      <br/><a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html"><img src="pictures/xtd.forms.png"/></a> The <a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html">xtd.forms</a> library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows, Apple macOS and linux operating system.
      <br/><br/><font size="+2">xtd.tunit</font>
      <br/><a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html"><img src="pictures/xtd.tunit.png"/></a> The <a href="https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__tunit.html">xtd.tunit</a> library is a unit-testing framework for modern C++17/20 inspired by <a href="">Microsoft.VisualStudio.TestTools.Cpp</a>.
      <br/><br/>See <a href="">xtd libraries hierarchy</a>.
      </>
    ),
  },
  {
    title: 'Objectives and Mission',
    description: (
      <>
      • xtd is a powerful, yet easy to use platform to build your applications upon. 
      <br/>• xtd is modular and scalable from embedded applications.
      <br/>• xtd provides consistent, comprehensive and comprehensible programming interfaces. 
      <br/>• xtd favors simplicity over complexity ("as simple as possible, but not simpler").
      <br/>• xtd aims for consistency in <a href="docs/documentation">design</a>, <a href="docs/documentation/Design%20Guidelines/coding_conventions_guidelines">coding style</a> and <a href="https://gammasoft71.github.io/xtd/reference_guides/latest/index.html">documentation</a>.
      <br/>• xtd emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability.
      <br/>• xtd aims to make C++ programming fun again Guiding Principles
      <br/>• Strong focus on code quality, style, consistency and code readability – all code must satisfy our <a href="docs/documentation/Design%20Guidelines">coding style guide</a>.
      <br/>• Strong focus on tests (automated <a href="https://github.com/gammasoft71/xtd/tree/master/tests">unit tests</a> with high coverage).
      <br/>• Build on top of solid foundations – use existing proven C, C++ or Objective-C libraries (e.g. Win32 APi, Gtk4, AppKit,...) where it makes sense.
      </>
    ),
  },
  {
    title: 'Getting started',
    description: (
      <>
      • <a href="docs/downloads">Installation</a> provides download and install documentation.
      <br/>• <a href="docs/documentation/guides">Guides</a> provides xtd guides and tutorials.
      <br/>• <a href="https://github.com/gammasoft71/xtd/blob/master/examples/README.md">Examples</a> provides over 750 examples to help you use xtd, grouped by libraries and topics.
      </>
    ),
  },
];

function Feature({title, description}) {
  return (
    <div className={clsx('row')}>
      <div className="text--center">
      </div>
      <div className="text--left padding-horiz--md">
        <h3>{title}</h3>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
