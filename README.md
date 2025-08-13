# xtd

**Write Once, Run Everywhere!**

[![logo](https://github.com/gammasoft71/xtd/blob/master/docs/pictures/logo.png)](https://gammasoft71.github.io/xtd)

<br/>
**xtd (pronounced "extend") is a modern C++20 framework to create console (CLI), forms (GUI) and unit test (xUnit) multiplatform applications and libraries.**

<br/>
<div style={{ display: 'flex', justifyContent: 'left', flexWrap: 'wrap', gap: '30px', marginTop: '10px' }}>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Windows_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/macOS_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Linux_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/iOS_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Android_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/FreeBSD_h100.png"/></a>
  <a href="docs/documentation/portability"><img src="https://github.com/gammasoft71/xtd/blob/master/docs/pictures/os/Haiku_h100.png"/></a>
</div>
<br/>
<br/>
<br/>

## Introduction

This project is a documentation site for **[xtd](https://github.com/gammasoft71/xtd)**.

Website : https://gammasoft71.github.io/xtd/

## Continuous Integration build status

[![Deploy to GitHub Pages](https://github.com/gammasoft71/xtd/actions/workflows/deploy.yml/badge.svg)](https://github.com/gammasoft71/xtd/actions/workflows/deploy.yml)

## Installation

### Requirements

- [Node.js](https://nodejs.org/en/) >= 16.14

```
$ npm
```

This commands install all needed packages.

### Local Development

```
$ npm start
```

This command starts a local development server and opens up a browser window. Most changes are reflected live without having to restart the server.

### Build

```
$ npm run build
```

This command generates static content into the `build` directory and can be served using any static contents hosting service.

```
$ npm run serve
```

This command starts a local server from `build` directory and opens up a browser window.

### Deployment

```
$ yarn deploy
```

This command use `npm build` and deploy the `build` directory into the `gh-pages` branch.

> **Warning**
>
> An error may occur when the `gh-pages` **local** branch already exists. Delete it with :
>
> ```
> $ git branch -D gh-pages
> ```
>
> And then use the *deploy* command.

## Special thanks

This website is built using [Docusaurus 2](https://docusaurus.io/), a modern static website generator.
