(async () => {
  try {
    const { execa } = await import('execa');
    const fs = await import('fs');

    console.log('Init...');
    await execa('git', ['branch', '-D', 'gh-pages']);
    await execa('git', ['checkout', '--orphan', 'gh-pages']);
    console.log('Building...');
    await execa('yarn', ['build']);
    // Understand if it's dist or build folder
    const folderName = fs.existsSync('dist') ? 'dist' : 'build';
    await execa('git', ['--work-tree', folderName, 'add', '--all']);
    await execa('git', ['--work-tree', folderName, 'commit', '-m', 'gh-pages']);
    
    console.log('Pushing to gh-pages...');
    await execa('git', ['push', 'origin', 'HEAD:gh-pages', '--force']);
    console.log('Sync...');
    fs.rmSync(folderName, { recursive: true, force: true });
    console.log('Checkout...');
    await execa('git', ['checkout', '-f', 'docs']);
    console.log('Branch...');
    await execa('git', ['branch', '-D', 'gh-pages']);

    console.log('Successfully deployed');
  } catch (e) {
    console.log(e.message);
    process.exit(1);
  }
})();
