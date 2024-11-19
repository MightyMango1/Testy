import axios from 'axios';

// Function to make a POST request to run the C++ program

export function runCppProgram() {
    //create a post request to the server
  return axios.post('http://localhost:3000/run-cpp', {
    input : "Hello World"
  })
    //once a response is received, return the data from that response
    .then(response => response.data.output)
    
    .catch(error => {
      console.error('Error:', error);
      throw new Error('Error running C++ program');
    });
}


// Function to make a GET request to fetch data from the server
export function getData() {
    return axios.get('http://localhost:3000/get-data')
      .then(response => {
        console.log (response.data)
        return (response.data)})

      .catch(error => {
        console.error('Error:', error);
        throw new Error('Error fetching data from the server');
      });
  }

