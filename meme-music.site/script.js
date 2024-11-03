const memeImage = document.getElementById("meme-image");
const nextMemeButton = document.getElementById("next-meme");
const soundcloudPlayer = document.getElementById("soundcloud-player");

// Array of SoundCloud track URLs (replace with actual SoundCloud track URLs)
const soundcloudTracks = [
  "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/123456789",
  "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/987654321",
  "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/1122334455",
];

// Load a random SoundCloud track
function loadRandomTrack() {
  const randomTrack = soundcloudTracks[Math.floor(Math.random() * soundcloudTracks.length)];
  soundcloudPlayer.innerHTML = `<iframe width="100%" height="166" scrolling="no" frameborder="no" allow="autoplay" src="${randomTrack}"></iframe>`;
}

// Fetch a random meme from Meme API
async function fetchRandomMeme() {
  try {
    const response = await fetch("https://meme-api.com/gimme");
    const data = await response.json();
    memeImage.src = data.url;
  } catch (error) {
    console.error("Error fetching meme:", error);
  }
}

// Event listener for 'Next Meme' button
nextMemeButton.addEventListener("click", fetchRandomMeme);

// Initial Load
fetchRandomMeme();
loadRandomTrack();
