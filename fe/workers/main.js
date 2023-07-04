const myWorker = new Worker("worker.js");

myWorker.postMessage({first: 10000, second: 400});
console.log("Message posted to worker");

myWorker.onMessage = (e) => {
  result.textContent = e.data;
  console.log("Message received from worker");
};

worker.onerror = workerError;
function workerError(error) {
  console.error(error.message);
}

myWorker.terminate();
