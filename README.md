<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![project_license][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/yukil-30/the-wish-you-want">
    <img src="images/wish-you-want.svg" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">The Wish You Want</h3>

  <p align="center">
    Text-based C++ adventure game combining story and mini-games.
    <br />
    <a href="https://github.com/yukil-30/the-wish-you-want"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/yukil-30/the-wish-you-want">View Demo</a>
    &middot;
    <a href="https://github.com/yukil-30/the-wish-you-want/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/yukil-30/the-wish-you-want/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

Wish You Want is a C++ text-based adventure game that combines storytelling with interactive mini-games. You play as a young villager from Neverest, tasked with caring for your younger siblings while facing hunger and hardship. One day, a mysterious man named Jack tells you about a magical tree that appears once every 25 years and grants a single wish. To reach it, you must first collect three pieces of an enchanted map—each earned by completing a different game.

**Features:**
* **Interactive Storyline:** Make choices that shape your journey—whether to search for food in the market, venture into the forest, or trust strangers you meet along the way.
* **Mini-Games:** Unlock pieces of the enchanted map by completing:
    - Blackjack - Defeat the dealer three times.
    - Hangman - Guess the hidden word before it's too late.
    - Number Guessing Game - Outsmart the challenge with logic and luck.
* **Narrative Immersion:** The game features ASCII art, text formatting (bold, colored text), and a narrator character to guide your decisions.
* **Replayable Choices:** Each run can be slightly different depending on your decisions and the order in which you choose to tackle the mini-games.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![C++][C++]][c++-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

You’ll need a **C++ compiler** (e.g., `g++` or `clang++`) installed on your system.

* Check g++ version
  
  ```sh
  g++ --version
  ```


### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yukil-30/the-wish-you-want.git
   cd the-wish-you-want
   ```
2. Compile the project: 

   **Linux/macOS**
   ```sh
   g++ src/*.cpp -Iinclude -o adventure
   ```
   **Windows**
   ```sh
   g++ src/*.cpp -Iinclude -o adventure.exe
   ```
3. Run the executable: 

   **Linus/macOS**
   ```sh
   ./adventure
   ```
   **Windows**
   ```sh
   adventure.exe
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ROADMAP -->
<!-- ## Roadmap

- [ ] Feature 1
- [ ] Feature 2
- [ ] Feature 3
    - [ ] Nested Feature

See the [open issues](https://github.com/github_username/repo_name/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p> -->

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Best README Template](https://github.com/othneildrew/Best-README-Template/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/yukil-30/the-wish-you-want.svg?style=for-the-badge
[contributors-url]: https://github.com/yukil-30/the-wish-you-want/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/yukil-30/the-wish-you-want.svg?style=for-the-badge
[forks-url]: https://github.com/yukil-30/the-wish-you-want/network/members
[stars-shield]: https://img.shields.io/github/stars/yukil-30/the-wish-you-want.svg?style=for-the-badge
[stars-url]: https://github.com/yukil-30/the-wish-you-want/stargazers
[issues-shield]: https://img.shields.io/github/issues/yukil-30/the-wish-you-want.svg?style=for-the-badge
[issues-url]: https://github.com/yukil-30/the-wish-you-want/issues
[license-shield]: https://img.shields.io/github/license/yukil-30/the-wish-you-want.svg?style=for-the-badge
[license-url]: https://github.com/yukil-30/the-wish-you-want/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/yuki-li123
[product-screenshot]: images/screenshot.png
[C++]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[c++-url]: https://isocpp.org/
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
