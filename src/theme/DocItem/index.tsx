import React from 'react';
import DocItemLayout from '@theme/DocItem/Layout';
import DocItemContent from '@theme/DocItem/Content';
import type { Props } from '@theme/DocItem';

export default function DocItem(props: Props): JSX.Element {
  return (
    <DocItemLayout
      {...props}
      // La ligne suivante supprime la TOC à droite
      toc={null}
    >
      <DocItemContent {...props} />
    </DocItemLayout>
  );
}