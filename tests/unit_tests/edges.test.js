describe('igraph.js', () => {
  it('edges', async () => {
    const igraph = global.igraph;

    const g = new igraph.graph();
    igraph.empty(g, 10, true);

    const edges = [0, 1, 1, 2, 2, 3, 2, 2];
    const v = new igraph.vector_int(edges);

    igraph.add_edges(g, v, 0);

    const ec = igraph.ecount(g);
    const ec2 = edges.length / 2;
    expect(ec).toEqual(ec2);

    igraph.destroy(g);
    g.delete();
    v.delete();
  });
});
