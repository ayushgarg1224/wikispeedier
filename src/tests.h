class Tests{
    public:
        void runAllTests();
        /* Graph */
        void testGraphSize();
        void testLinks();
        void testAddNode();

        /* WikiNode */
        void testIsLinkedTo();
        void testGetLinks();

        /* BFS */
        void testValidPath();
        void testImpossiblePath();
        void testEqualPathsBFS();
};