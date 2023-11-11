const data = {
    'nodes': [
        {'id': 'Microsoft', 'group': 'main'},
        {'id': 'Amazon', 'group': 'hardware'},
        {'id': 'HTC', 'group': 'hardware'},
        {'id': 'Samsung', 'group': 'hardware'},
        {'id': 'Apple', 'group': 'hardware'},
        {'id': 'Motorola', 'group': 'hardware'},
        {'id': 'Nokia', 'group': 'hardware'},
        {'id': 'Kodak', 'group': 'hardware'},
        {'id': 'Barnes & Noble', 'group': 'hardware'},
        {'id': 'Foxconn', 'group': 'hardware'},
        {'id': 'Oracle', 'group': 'software'},
        {'id': 'Google', 'group': 'software'},
        {'id': 'Inventec', 'group': 'software'},
        {'id': 'LG', 'group': 'hardware'},
        {'id': 'RIM', 'group': 'hardware'},
        {'id': 'Sony', 'group': 'hardware'},
        {'id': 'Qualcomm', 'group': 'hardware'},
        {'id': 'Huawei', 'group': 'hardware'},
        {'id': 'ZTE', 'group': 'hardware'},
        {'id': 'Ericsson', 'group': 'hardware'},

    ],
    'links': [
        {'source': 'Microsoft', 'target': 'Amazon', 'type': 'down'},
        {'source': 'Microsoft', 'target': 'HTC', 'type': 'up'},
        {'source': 'Samsung', 'target': 'Apple', 'type': 'down'},
        {'source': 'Motorola', 'target': 'Apple', 'type': 'down'},
        {'source': 'Nokia', 'target': 'Apple', 'type': 'up'},
        {'source': 'HTC', 'target': 'Apple', 'type': 'down'},
        {'source': 'Kodak', 'target': 'Apple', 'type': 'down'},
        {'source': 'Microsoft', 'target': 'Barnes & Noble', 'type': 'down'},
        {'source': 'Microsoft', 'target': 'Foxconn', 'type': 'down'},
        {'source': 'Oracle', 'target': 'Google', 'type': 'down'},
        {'source': 'Oracle', 'target': 'Barnes & Noble', 'type': 'down'},
        {'source': 'Oracle', 'target': 'Microsoft', 'type': 'up'},
        {'source': 'Apple', 'target': 'HTC', 'type': 'down'},
        {'source': 'Microsoft', 'target': 'Inventec', 'type': 'down'},
        {'source': 'Samsung', 'target': 'Kodak', 'type': 'up'},
        {'source': 'LG', 'target': 'Kodak', 'type': 'up'},
        {'source': 'RIM', 'target': 'Kodak', 'type': 'down'},
        {'source': 'Sony', 'target': 'LG', 'type': 'down'},
        {'source': 'Kodak', 'target': 'LG', 'type': 'up'},
        {'source': 'Apple', 'target': 'Nokia', 'type': 'up'},
        {'source': 'Qualcomm', 'target': 'Nokia', 'type': 'up'},
        {'source': 'Apple', 'target': 'Motorola', 'type': 'down'},
        {'source': 'Microsoft', 'target': 'Motorola', 'type': 'down'},
        {'source': 'Motorola', 'target': 'Microsoft', 'type': 'down'},
        {'source': 'Huawei', 'target': 'ZTE', 'type': 'down'},
        {'source': 'Ericsson', 'target': 'ZTE', 'type': 'down'},
        {'source': 'Ericsson', 'target': 'Foxconn', 'type': 'down'},
        {'source': 'Kodak', 'target': 'Samsung', 'type': 'up'},
        {'source': 'Apple', 'target': 'Samsung', 'type': 'down'},
        {'source': 'Kodak', 'target': 'RIM', 'type': 'down'},
        {'source': 'Nokia', 'target': 'Qualcomm', 'type': 'down'},
        {'source': 'Nokia', 'target': 'ZTE', 'type': 'up'}
    ]
}

const width = window.innerWidth;
const height = window.innerHeight;
const color = d3.scaleOrdinal(d3.schemeCategory10);

const svg = d3.select('#stage')
                .append('svg')
                .attr('width', width)
                .attr('height', height)
                .attr('viewBox', [0, 0, width, height])
                .attr('style', 'max-width: 100%; height: auto;');

// Create the force simulation
const simulation =
    d3.forceSimulation(data.nodes)
        .force('link', d3.forceLink(data.links).id(d => d.id))
        .force(
            'charge',
            d3.forceManyBody().strength(
                -500))
        .force('center', d3.forceCenter(width / 2, height / 2))
        .force(
            'collision',
            d3.forceCollide().radius(60))
        .on('tick', ticked);


// Add a line for each link, and a circle for each node.
const link = svg.append('g')
                 .attr('stroke', '#999')
                 .selectAll()
                 .data(data.links)
                 .join('line')
                 .attr('stroke-width', d => Math.sqrt(d.value));

// Append a group for each node to hold both the rectangle and text
const node = svg.selectAll('.node')
                 .data(data.nodes)
                 .enter()
                 .append('g')
                 .attr('class', 'node')
                 .call(d3.drag()
                           .on('start', dragstarted)
                           .on('drag', dragged)
                           .on('end', dragended));

// Add rectangles to the nodes
node.append('rect')
    .attr('width', 100)
    .attr('height', 30)
    .attr('x', -10)
    .attr('y', -14)
    .attr('stroke', '#fff')
    .attr('stroke-width', 1.5)
    .attr('fill', d => color(d.group));

// Add labels to nodes
node.append('text').attr('dy', '.35em').text(d => d.id);

// Set the position attributes of links and nodes each time the simulation ticks
function ticked() {
    link.attr('x1', d => d.source.x)
        .attr('y1', d => d.source.y)
        .attr('x2', d => d.target.x)
        .attr('y2', d => d.target.y);

    node.attr('transform', d => `translate(${d.x},${d.y})`);
}

function dragstarted(event) {
    if (!event.active) simulation.alphaTarget(0.3).restart();
    event.subject.fx = event.subject.x;
    event.subject.fy = event.subject.y;
}

function dragged(event) {
    event.subject.fx = event.x;
    event.subject.fy = event.y;
}

function dragended(event) {
    if (!event.active) simulation.alphaTarget(0);
    event.subject.fx = null;
    event.subject.fy = null;
}
