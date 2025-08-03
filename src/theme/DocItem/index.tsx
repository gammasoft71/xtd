import React from 'react';
import OriginalDocItem from '@theme-original/DocItem';
import type { Props } from '@theme/DocItem';

export default function DocItem(props: Props): JSX.Element {
  // Force TOC à null (donc désactive la colonne de droite)
  return <OriginalDocItem {...props} toc={null} />;
}