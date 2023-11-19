const igraph = require('./igraph')

beforeAll(async () => {
  global.igraph = await igraph();
});
