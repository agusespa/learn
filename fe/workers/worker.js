onMessage = (e) => {
	console.log("Message received from main script");
	const workerResult = `Result: ${e.data.first * e.data.second}`;
	console.log("Posting message back to main script");
	postMessage(workerResult);
};
