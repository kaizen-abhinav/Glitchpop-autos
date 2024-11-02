// Function to toggle servo on NodeMCU
function toggleServo() {
    fetch('http://YOUR_NODEMCU_IP/toggle-servo')
      .then(response => response.text())
      .then(data => {
        document.getElementById('servoStatus').innerText = "Status: " + data;
      })
      .catch(error => console.error('Error:', error));
  }
  
  // Function to show different tabs
  function showTab(tabName) {
    document.querySelectorAll('.tab').forEach(tab => tab.classList.remove('active'));
    document.getElementById(tabName).classList.add('active');
  }
  
  // Function to generate useless ideas
  function generateIdea() {
    fetch('https://api.openai.com/v1/engines/davinci/completions', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'Authorization': 'Bearer key'
      },
      body: JSON.stringify({
        prompt: "Generate a useless idea:",
        max_tokens: 50,
        temperature: 0.7
      })
    })
    .then(response => response.json())
    .then(data => {
      const idea = data.choices[0].text.trim();
      document.getElementById('ideaOutput').innerText = "Idea: " + idea;
    })
    .catch(error => console.error('Error:', error));
  }
  
