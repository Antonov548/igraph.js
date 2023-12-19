import { useEffect, useRef, useState } from 'react';

import Box from '@mui/material/Box';
import InputLabel from '@mui/material/InputLabel';
import MenuItem from '@mui/material/MenuItem';
import FormControl from '@mui/material/FormControl';
import Select from '@mui/material/Select';
import { ForceGraph3D } from 'react-force-graph';
import { Typography } from '@mui/material';

export const Famous = ({ igraph }) => {
  const fgRef = useRef();

  const [name, setName] = useState('walther');

  const [data, setData] = useState({
    nodes: [],
    links: [],
  });

  useEffect(() => {
    if (igraph !== null) {
      const g = new igraph.graph();
      igraph.famous(g, name);

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

      igraph.destroy(g);

      e.delete();
      g.delete();
    }
  }, [igraph, name]);

  useEffect(() => {
    fgRef.current.camera().rotationSpeed = 0.005;
  }, []);

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
        Choose name of graph.
      </Typography>
      <FormControl sx={{ m: 1, minWidth: 120 }} size="small">
        <InputLabel
          sx={{
            color: 'gray',
            '&.Mui-focused': {
              color: 'gray',
            },
          }}
          id="graph-name-label"
        >
          Name
        </InputLabel>
        <Select
          displayEmpty
          labelId="graph-name-label"
          id="graph-select"
          value={name}
          defaultValue={name}
          label="Name"
          onChange={(event) => setName(event.target.value)}
          sx={{
            color: 'silver',
            '.MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgba(228, 219, 233, 0.25)',
            },
            '&.Mui-focused .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgba(228, 219, 233, 0.25)',
            },
            '&:hover .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgba(228, 219, 233, 0.25)',
            },
            '.MuiSvgIcon-root ': {
              fill: 'gray !important',
            },
          }}
        >
          <MenuItem value={'housex'}>housex</MenuItem>
          <MenuItem value={'krackhardt_kite'}>krackhardt kite</MenuItem>
          <MenuItem value={'walther'}>walther</MenuItem>
          <MenuItem value={'grotzsch'}>grotzsch</MenuItem>
          <MenuItem value={'levi'}>levi</MenuItem>
          <MenuItem value={'meredith'}>meredith</MenuItem>
          <MenuItem value={'noperfectmatching'}>noperfectmatching</MenuItem>
        </Select>
      </FormControl>
      <ForceGraph3D
        width={400}
        height={400}
        ref={fgRef}
        graphData={data}
        linkDirectionalParticleColor={() => 'red'}
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
