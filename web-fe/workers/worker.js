onmessage = (e) => {
	const workerResult = e.data.first * e.data.second;
	postMessage(workerResult);
};
