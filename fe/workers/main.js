const myWorker = new Worker("worker.js");

myWorker.postMessage([10000,50]);
console.log("Message posted to worker");

myWorker.onmessage = (e) => {
  result.textContent = e.data;
  console.log("Message received from worker");
};
console.log(myWorker);

myWorker.terminate();
