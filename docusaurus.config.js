// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');

/** @type {import('@docusaurus/types').Config} */
const config = {
  //title: 'xtd',
  //tagline: 'xtd (pronounced "extend") is a modern C++17/20 framework to create console, GUI and unit test applications on Microsoft Windows, macOS, Linux, iOS and android (*).',
  title: ' ',
  tagline: ' ',
  url: 'https://gammasoft71.github.io',
  baseUrl: '/xtd/',
  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',
  favicon: 'img/favicon.ico',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'gammasoft71', // Usually your GitHub org/user name.
  projectName: 'xtd', // Usually your repo name.
  trailingSlash: false,

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
          sidebarPath: require.resolve('./sidebars.js'),
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/gammasoft71/xtd/tree/docs',
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
            docId: 'intro',
            position: 'left',
            label: 'Examples',
          },
          {
            type: 'doc',
            docId: 'intro',
            position: 'left',
            label: 'Downloads',
          },
          {
            type: 'doc',
            docId: 'intro',
            position: 'left',
            label: 'Documentation',
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
            href: 'https://gammasoft71.wixsite.com/gammasoft/',
            label: 'Gammasoft',
            position: 'left',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            title: 'Learn',
            items: [
              {
                label: 'Introduction',
                to: '/docs/intro',
              },
              {
                label: 'Installation',
                href: '/docs/downloads',
              },
              {
                label: 'Documentation',
                href: '/docs/documentation',
              },
            ]
          },
          {
            title: 'Social',
            items: [
              {
                label: 'Discord',
                href: 'https://discordapp.com/users/gammasoft#9288',
              },
              {
                label: 'Facebook',
                href: 'https://www.facebook.com/gammasoft71',
              },
              {
                label: 'Twitter',
                href: 'https://twitter.com/gammasoft71',
              },
            ]
          },
          {
            title: 'Support',
            items: [
              {
                label: 'Issues tracker',
                href: 'https://github.com/gammasoft71/xtd/issues',
              },
              {
                label: 'Github',
                href: 'https://github.com/gammasoft71',
              },
            ]
          },
          {
            title: 'More',
            items: [
/*               {
                label: 'Design Guidelines',
                to: '/docs/documentation/design_guidelines',
              }, */
              {
                label: 'License',
                to: '/docs/documentation/license',
              },
              {
                label: 'Roadmap',
                to: '/docs/documentation/roadmap',
              },
            ]
          }
        ],
        copyright: `Copyright © ${new Date().getFullYear()} Gammasoft, Inc. Built with Docusaurus.`,
      },
      prism: {
        theme: lightCodeTheme,
        darkTheme: darkCodeTheme,
      },
    }),
};

module.exports = config;
