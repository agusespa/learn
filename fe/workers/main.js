const myWorker = new Worker("worker.js");

myWorker.postMessage({first: 10000, second: 400});
console.log("Message posted to worker");

myWorker.onmessage = (e) => {
    console.log("Result received: " + e.data);
};
