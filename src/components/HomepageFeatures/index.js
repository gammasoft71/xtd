import React from 'react';
import clsx from 'clsx';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Feature',
    Svg: require('@site/static/img/undraw_in_sync_re_jlqd.svg').default,
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
    Svg: require('@site/static/img/undraw_next_tasks_re_5eyy.svg').default,
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
    Svg: require('@site/static/img/undraw_programming_re_kg9v.svg').default,
    description: (
      <>
      • Installation provides download and install documentation.
      <br/>• Guides provides xtd guides and tutorials.
      <br/>• Examples provides over 500 examples to help you use xtd, grouped by libraries and topics.
      </>
    ),
  },
];

function Feature({Svg, title, description}) {
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
