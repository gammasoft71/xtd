import React from 'react';
import clsx from 'clsx';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Latest news',
    description: (
      <>
      • <a href="https://github.com/gammasoft71/xtd/blob/master/docs/news.md#xtdtunit-is-compatible-with-test-explorer-window-of-visual-studio-2019-or-later-november-18-2022">xtd.tunit is compatible with Test Explorer window of Visual Studio 2019 or later - November 18, 2022</a>
      <br/>• <a href="https://github.com/gammasoft71/xtd/blob/master/docs/news.md#release-xtd-010-beta-october-10-2021">Release xtd 0.1.0 (beta) - October 10, 2021</a>
      </>
    ),
  },
  {
    title: 'Feature',
    description: (
      <>
      • Free and open-source (MIT License). A collection of native C++ classes libraries, to complete std.
      <br/>• API close to the .net API with modern C++ approach and full integration with the std standard.
      <br/>• xtd is designed to manage GUI controls and dialogs in pure native mode or with CSS styles.
      <br/>• Written in efficient, modern c++17/20 with RAII programming idiom.
      <br/>• And highly portable and available on many different platforms.
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
      <br/>• xtd aims for consistency in design, coding style and documentation. 
      <br/>• xtd emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability.
      </>
    ),
  },
  {
    title: 'Getting started',
    description: (
      <>
      • Installation provides download and install documentation.
      <br/>• Guides provides xtd guides and tutorials.
      <br/>• Examples provides over 500 examples to help you use xtd, grouped by libraries and topics.
      </>
    ),
  },
];

function Feature({title, description}) {
  return (
    <div className={clsx('row row--4')}>
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
