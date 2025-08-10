// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
//const darkCodeTheme = require('prism-react-renderer/themes/dracula');
const darkCodeTheme = require('prism-react-renderer/themes/palenight');

/** @type {import('@docusaurus/types').Config} */
const config = {
  //title: 'xtd',
  title: ' ',
  //tagline: 'xtd (pronounced "extend") is a modern C++20 framework to create console, GUI and unit test applications on Microsoft Windows, macOS, Linux, iOS and android (*).',
  favicon: 'pictures/xtd.ico',

  // Set the production url of your site here
  url: 'https://gammasoft71.github.io',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/xtd/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'gammasoft71', // Usually your GitHub org/user name.
  projectName: 'xtd', // Usually your repo name.
  trailingSlash: false,

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  // Even if you don't use internalization, you can use this field to set useful
  // metadata like html lang. For example, if your site is Chinese, you may want
  // to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: false,
          showLastUpdateAuthor: false,
          showLastUpdateTime: false,
        },
        blog: false,
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'xtd',
        logo: {
          alt: 'My Site Logo',
          src: 'pictures/logo.png',
        },
        items: [
          {
            type: 'doc',
            docId: 'news',
            position: 'left',
            label: 'News',
          },
          {
            type: 'doc',
            docId: 'gallery',
            position: 'left',
            label: 'Gallery',
          },
          {
            type: 'doc',
            docId: 'examples',
            position: 'left',
            label: 'Examples',
          },
          {
            type: 'doc',
            docId: 'downloads',
            position: 'left',
            label: 'Downloads',
          },
          {
            type: 'doc',
            docId: 'documentation/README',
            position: 'left',
            label: 'Documentation',
          },
          {
            href: 'https://github.com/gammasoft71/xtd/wiki',
            label: 'Wiki',
            position: 'left',
          },
          {
            type: 'doc',
            docId: 'Support/README',
            position: 'left',
            label: 'Support',
          },
          {
            href: 'https://github.com/gammasoft71/xtd',
            label: 'Sources',
            position: 'left',
          },
          {
            href: 'https://sourceforge.net/projects/xtdpro/',
            label: 'Project',
            position: 'left',
          },
          {
            href: 'https://gammasoft71.github.io/',
            label: 'Gammasoft',
            position: 'left',
            target: '_self',
            rel: null,
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            html: `
              <div style="display: flex; justify-content: center; gap: 1rem; align-items: center;">
                <a href="https://gammasoft71.github.io/xtd"><img src="https://gammasoft71.github.io/xtd/pictures/xtd32.png" alt="xtd" /></a>
                <a href="https://github.com/gammasoft71/xtd"><img src="https://gammasoft71.github.io/xtd/pictures/github32.png" alt="GitHub" /></a>
                <a href="https://sourceforge.net/projects/xtdpro"><img src="https://gammasoft71.github.io/xtd/pictures/sourceforge32.png" alt="SourceForge" /></a>
                <a href="https://www.facebook.com/gammasoft71"><img src="https://gammasoft71.github.io/xtd/pictures/facebook32.png" alt="Facebook" /></a>
                <a href="https://x.com/gammasoft71"><img src="https://gammasoft71.github.io/xtd/pictures/x32.png" alt="x" /></a>
                <a href="https://discordapp.com/users/gammasoft#9288"><img src="https://gammasoft71.github.io/xtd/pictures/discord32.png" alt="Discord" /></a>
                <a href="mailto:gammasoft71@gmail.com"><img src="https://gammasoft71.github.io/xtd/pictures/mail32.png" alt="Mail" /></a>
              </div>
            `,
          },
        ],
        copyright: `© ${new Date().getFullYear()} Gammasoft.`,
      },
      prism: {
        theme: lightCodeTheme,
        darkTheme: darkCodeTheme,
      },
    }),
};

module.exports = config;
