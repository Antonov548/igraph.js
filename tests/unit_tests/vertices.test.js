describe('igraph.js', () => {
  it('vertices', async () => {
    const igraph = global.igraph;

    const v = new igraph.vector_int([0, 1, 1, 2, 2, 3, 2, 2]);

    const g = new igraph.graph();
    igraph.create(g, v, 0, false);

    v.delete();

    igraph.add_vertices(g, 10, 0);
    expect(igraph.vcount(g)).toEqual(14);

    igraph.add_vertices(g, 0, 0);
    expect(igraph.vcount(g)).toEqual(14);

    igraph.destroy(g);
    g.delete();
  });
});
