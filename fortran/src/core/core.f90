module core
    use util
    implicit none
    type Runner
        integer :: nodes
        integer :: edges
        integer :: graphs
        integer :: queries
        integer :: fc
    end type
contains
    subroutine runner_initialize(r, fn, fc)
        type(Runner), intent(out) :: r
        character(len=*), intent(in) :: fn
        integer, intent(in) :: fc
        r%fc = fc
        open(fc, file = fn, status = "old")
        read (fc, *) r%nodes, r%edges, r%graphs, r%queries
    end subroutine
    subroutine runner_finalize(r)
        type(Runner), intent(in) :: r
        close(r%fc)
    end subroutine
    subroutine runner_run(r, verbose, show_graph, show_path)
        type(Runner), intent(in) :: r
        logical, intent(in) :: verbose
        logical, intent(in) :: show_graph
        logical, intent(in) :: show_path
        integer :: i
        integer :: j
        type(Graph) :: g
        integer :: src
        integer :: dest
        logical :: res
        do i = 1, r%graphs
            if (verbose) then
                print *, "graph", i
            end if
            call graph_initialize(g, r%fc, r%nodes, r%edges)
            if (show_graph) then
                call graph_log(g)
            end if
            do j = 1, r%queries
                if (verbose) then
                    print *, "query", j
                end if
                read (r%fc, *) src, dest
                src = src + 1
                dest = dest + 1
                res = graph_bfs(g, src, dest, show_path)
                if (verbose) then
                    if (res) then
                        print *, src, "->", dest
                    else
                        print *, src, "X", dest
                    end if
                end if
            end do
            call graph_finalize(g)
        end do
    end subroutine
end module
