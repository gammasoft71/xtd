<h1 align="center">
    <p align="center">
        Xtd website
    </p>
</h1>



## Introduction

This project is a documentation site for **[xtd](https://github.com/gammasoft71/xtd)**.

Website : https://gammasoft71.github.io/xtd/

## Installation

### Requirements

- [Node.js](https://nodejs.org/en/) >= 16.14

```
$ yarn
```

This commands install all needed packages.

### Local Development

```
$ yarn start
```

This command starts a local development server and opens up a browser window. Most changes are reflected live without having to restart the server.

### Build

```
$ yarn build
```

This command generates static content into the `build` directory and can be served using any static contents hosting service.

```
$ yarn serve
```

This command starts a local server from `build` directory and opens up a browser window.

### Deployment

```
$ yarn deploy
```

This command use `yarn build` and deploy the `build` directory into the `gh-pages` branch.

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
