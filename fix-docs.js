#!/usr/bin/env node

const fs = require('fs');
const path = require('path');

const exts = ['.md', '.mdx'];

function scanAndFix(dir) {
  fs.readdirSync(dir, { withFileTypes: true }).forEach(entry => {
    const fullPath = path.join(dir, entry.name);

    if (entry.isDirectory()) {
      scanAndFix(fullPath);
    } else if (exts.includes(path.extname(entry.name))) {
      let content = fs.readFileSync(fullPath, 'utf-8');
      const original = content;

      // 1. Corrige les liens [text](#) → [text](javascript:void(0))
      content = content.replace(/\[([^\]]+)\]\(#\)/g, '[$1](javascript:void(0))');

      // 2. Remplace <...> dans inline code par `xtd::func<...>`
      content = content.replace(/<(\.\.\.)>/g, '`<...>`'); // simple
      content = content.replace(/xtd::(func|action)<(.*?)>/g, '`xtd::$1<$2>`');

      // 3. Corrige HTML auto-fermant (ex: <br>, <img>)
      content = content.replace(/<br>/g, '<br />');
      content = content.replace(/<img(.*?)>/g, '<img$1 />');

      if (content !== original) {
        console.log(`✔️  Fixed: ${fullPath}`);
        fs.writeFileSync(fullPath, content);
      }
    }
  });
}

// Dossier à scanner
const docsDir = process.argv[2] || './docs';
console.log(`🔍 Scanning directory: ${docsDir}`);
scanAndFix(docsDir);
console.log('✅ Done.');
