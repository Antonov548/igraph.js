import { useEffect, useState } from 'react';
import Box from '@mui/material/Box';
import Drawer from '@mui/material/Drawer';
import List from '@mui/material/List';
import Typography from '@mui/material/Typography';
import Divider from '@mui/material/Divider';
import ListItem from '@mui/material/ListItem';
import Link from '@mui/material/Link';
import { Famous } from './graphs/Famous';
import { ShortestPath } from './graphs/ShortestPath';
import loadModule from './igraph';

const drawerWidth = 300;

const names = [
  'famous',
  'empty',
  'get_shortest_path',
  'add_edges',
  'add_vertices',
].sort();

export function App() {
  const [igraph, setIgraph] = useState(null);

  const references = [
    {
      name: '.famous',
      comp: <Famous igraph={igraph} />,
      doc: 'Return graph by name.',
    },
    { name: '.add_vertices', comp: null, doc: 'Add vertices to a graph.' },
    { name: '.add_edges', comp: null, doc: 'Add edges to a graph.' },
    {
      name: '.get_shortest_path',
      comp: <ShortestPath igraph={igraph} />,
      doc: '	Shortest (directed or undirected) paths between vertices.',
    },
  ].sort((l, r) => l.name.localeCompare(r.name));

  useEffect(() => {
    const igraph = loadModule({
      locateFile: () => require('./igraph.wasm'),
    }).then((module) => {
      setIgraph(module);
    });
  }, []);

  const drawer = (
    <div>
      <Box sx={{ pt: 3, pb: 2, pl: 3 }}>
        <Typography
          sx={{
            fontWeight: 'normal',
            color: 'white',
            fontFamily: 'sans-serif',
          }}
        >
          igraph.js
        </Typography>
      </Box>
      <Divider sx={{ background: 'rgb(40, 40, 40)' }} variant="fullWidth" />
      <List>
        <Typography
          sx={{
            pt: 3,
            pl: 3,
            pb: 1.3,
            fontWeight: 'medium',
            color: 'white',
            fontFamily: 'sans-serif',
            fontSize: '0.9em',
          }}
        >
          Functions
        </Typography>
        {names.map((text, index) => (
          <ListItem key={text} sx={{ pl: 3 }} disablePadding>
            <Typography
              onClick={() => console.log('work')}
              sx={{
                pt: 1.3,
                fontFamily: 'sans-serif',
                fontSize: '1em',
                cursor: 'pointer',
                color: 'rgb(180, 180, 180)',
                '&:hover': {
                  color: '#1d97e0',
                  cursor: 'pointer',
                },
              }}
            >
              {text}
            </Typography>
          </ListItem>
        ))}
      </List>
    </div>
  );

  return (
    <Box sx={{ display: 'flex' }}>
      <Box
        component="nav"
        sx={{
          width: { sm: drawerWidth },
          flexShrink: { sm: 0 },
          background: 'rgb(9, 9, 15)',
        }}
      >
        <Drawer
          variant="permanent"
          sx={{
            display: { sm: 'block' },
            background: 'rgb(9, 9, 15)',
            '& .MuiDrawer-paper': {
              boxSizing: 'border-box',
              width: drawerWidth,
              backgroundColor: 'rgb(18, 18, 24)',
              borderColor: 'rgb(20, 20, 50)',
              borderWidth: '1px',
            },
          }}
          open
        >
          {drawer}
        </Drawer>
      </Box>
      <Box
        component="main"
        sx={{
          background: 'rgb(9, 9, 15)',
          width: { sm: `calc(100% - ${drawerWidth}px)` },
          height: 'auto',
          minHeight: '100vh',
          display: 'flex',
          flexDirection: 'column',
        }}
      >
        <Box sx={{ display: 'flex', justifyContent: 'center' }}>
          <Box sx={{ pt: 10, width: '60%', height: '50%' }}>
            <Typography
              sx={{
                color: 'rgb(90, 90, 90)',
                fontSize: '1em',
                fontFamily: 'sans-serif',
              }}
            >
              Documentation
            </Typography>
            <Typography
              sx={{
                background: '-webkit-linear-gradient(white, gray)',
                fontFamily: 'sans-serif',
                WebkitBackgroundClip: 'text',
                WebkitTextFillColor: 'transparent',
                fontSize: '2em',
              }}
            >
              Welcome to igraph.js
            </Typography>
            <Typography
              sx={{
                pt: 1.4,
                fontFamily: 'sans-serif',
                color: 'gray',
                width: '70%',
              }}
            >
              Documentation of igraph.js library with examples. igraph.js is an
              JavaScript interface of the{' '}
              <Link
                target="_blank"
                href="https://github.com/igraph/igraph"
                rel="noopener noreferrer"
              >
                igraph
              </Link>{' '}
              network analysis library compiled to WebAssembly using Emscripten.
            </Typography>
            <Typography
              sx={{
                pt: 1.4,
                fontFamily: 'sans-serif',
                color: 'gray',
                width: '70%',
              }}
            >
              Graphs visualization is implemented using{' '}
              <Link
                target="_blank"
                href="https://github.com/vasturiano/react-force-graph"
                rel="noopener noreferrer"
              >
                react-force-graph
              </Link>{' '}
              library.
            </Typography>
            <Box sx={{ pt: 6, pb: 6 }}>
              <Divider sx={{ bgcolor: 'rgb(40, 40, 40)' }} variant="middle" />
            </Box>
            <Typography
              sx={{
                background: '-webkit-linear-gradient(white, gray)',
                fontFamily: 'sans-serif',
                WebkitBackgroundClip: 'text',
                WebkitTextFillColor: 'transparent',
                fontSize: '1.5em',
              }}
            >
              Functions
            </Typography>
            {references.map((text, index) => (
              <Box
                sx={{
                  pt: 1.3,
                  pb: 1.3,
                }}
              >
                <Typography
                  onClick={() => console.log('work')}
                  sx={{
                    display: 'inline-block',
                    fontFamily: 'sans-serif',
                    fontSize: '1.1em',
                    cursor: 'pointer',
                    color: '#1d97e0',
                  }}
                >
                  {text.name}
                </Typography>
                <Typography
                  sx={{
                    pt: 1.3,
                    fontFamily: 'sans-serif',
                    fontSize: '0.95em',
                    color: 'rgb(160, 160, 160)',
                  }}
                >
                  {text.doc}
                </Typography>
                {text.comp && text.comp}
              </Box>
            ))}
          </Box>
        </Box>
      </Box>
    </Box>
  );
}

export default App;
