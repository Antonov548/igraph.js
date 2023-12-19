import { useEffect, useRef, useState, useCallback } from 'react';

import Box from '@mui/material/Box';
import { ForceGraph2D } from 'react-force-graph';
import { Typography } from '@mui/material';

export const ShortestPath = ({ igraph }) => {
  const fgRef = useRef();

  const [selected, setSelected] = useState([]);
  const [graph, setGraph] = useState(null);

  const [vertices, setVertices] = useState([]);
  const [edges, setEdges] = useState([]);

  const [data, setData] = useState({
    nodes: [],
    links: [],
  });

  useEffect(() => {
    if (igraph !== null) {
      const g = new igraph.graph();

      igraph.famous(g, 'dodecahedral');

      setGraph(g);

      // create empty int vector - initialize it
      const e = new igraph.vector_int([]);

      // get edge list from graph
      igraph.get_edgelist(g, e, false);

      const edgelist = e.data;

      const graphData = {
        nodes: [],
        links: [],
      };

      for (let i = 0; i < g.n; ++i) {
        graphData.nodes.push({ id: i });
      }

      for (let i = 0; i < edgelist.length / 2; ++i) {
        graphData.links.push({
          source: edgelist[i * 2],
          target: edgelist[i * 2 + 1],
        });
      }

      setData(graphData);
      
      e.delete();
    }
  }, [igraph]);

  useEffect(() => {
    if (selected.length === 2) {
      const vpath = new igraph.vector_int();
      const epath = new igraph.vector_int();
  
      igraph.get_shortest_path(graph, vpath, epath, selected[0], selected[1], igraph.neimode.OUT);
  
      console.log(vpath.data);

      const vtx = [];
      for (const idx of vpath.data) {
        vtx.push(idx);
      }

      setVertices(vtx);

      const edg = [];
      for (const idx of epath.data) {
        edg.push(idx);
      }

      setEdges(edg);
  
      vpath.delete();
      epath.delete();
    }
  }, [selected, graph, igraph])

  const handleNodeClick = useCallback(node => {
    if (selected.length === 2) {
      setSelected([node.id]);
    } else {
      setSelected([...selected, node.id]);
    }
  }, [selected]);

  return (
    <Box
      sx={{
        pt: 3,
      }}
    >
      <Typography
        sx={{
          pb: 1,
          fontFamily: 'sans-serif',
          fontSize: '0.95em',
          color: 'rgb(160, 160, 160)',
        }}
      >
        Choose nodes by clicking to find closest path between them.
      </Typography>
      <ForceGraph2D
        width={400}
        height={400}
        ref={fgRef}
        graphData={data}
        linkColor={link => { const idx = edges.find(id => id === link.index); const color = idx === undefined ? 'gray' : 'red'; return color; }}
        nodeColor={node => { const idx = vertices.find(id => id === node.id); const color = idx === undefined ? '#1d97e0' : 'yellow'; return color; }}
        linkDirectionalParticleColor={() => 'red'}
        onNodeClick={handleNodeClick}
        backgroundColor="rgb(9, 9, 15)"
        onNodeDragEnd={(node) => {
          node.fx = node.x;
          node.fy = node.y;
          node.fz = node.z;
        }}
      />
    </Box>
  );
};
