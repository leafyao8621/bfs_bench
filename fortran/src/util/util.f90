module util
    type ListNode
        integer :: data
        type(ListNode), pointer :: next
    end type
    type List
        type(ListNode), pointer :: front
        type(ListNode), pointer :: back
    end type
    type Node
        logical :: visited
        integer :: prec
        type(List) :: idx
    end type
    type Graph
        integer :: nodes
        integer :: edges
        type(Node), dimension(:), allocatable :: al
    end type
contains
    subroutine push(l, d)
        type(List), intent(inout) :: l
        integer, intent(in) :: d
        type(ListNode), pointer :: temp
        allocate(temp)
        temp%data = d
        nullify(temp%next)
        if (.not. associated(l%front)) then
            l%front => temp
        end if
        if (associated(l%back)) then
            l%back%next => temp
        end if
        l%back => temp
    end subroutine
    subroutine pop(l)
        type(List), intent(inout) :: l
        type(ListNode), pointer :: temp
        if (.not. associated(l%front)) then
            return
        end if
        temp => l%front
        l%front => temp%next
        if (.not. associated(l%front)) then
            nullify(l%back)
        end if
        deallocate(temp)
    end subroutine
    subroutine graph_initialize(g, fc, nodes, edges)
        type(Graph), intent(out) :: g
        integer, intent(in) :: fc
        integer, intent(in) :: nodes
        integer, intent(in) :: edges
        integer :: i
        integer :: src
        integer :: dest
        g%nodes = nodes
        g%edges = edges
        allocate(g%al(nodes))
        do i = 1, nodes
            nullify(g%al(i)%idx%front)
            nullify(g%al(i)%idx%back)
        end do
        do i = 1, edges
            read (fc, *) src, dest
            src = src + 1
            dest = dest + 1
            call push(g%al(src)%idx, dest)
            call push(g%al(dest)%idx, src)
        end do
    end subroutine
    subroutine graph_finalize(g)
        type(Graph), intent(inout) :: g
        integer :: i
        do i = 1, g%nodes
            do while (associated(g%al(i)%idx%front))
                call pop(g%al(i)%idx)
            end do
        end do
    end subroutine
    subroutine graph_log(g)
        type(Graph), intent(in) :: g
        type(ListNode), pointer :: j
        do i = 1, g%nodes
            print *, i, ":"
            j => g%al(i)%idx%front
            do while (associated(j))
                print *, j%data
                j => j%next
            end do
        end do
    end subroutine
    function graph_bfs(g, src, dest, verbose)
        type(Graph), intent(inout) :: g
        integer, intent(in) :: src
        integer, intent(in) :: dest
        logical, intent(in) :: verbose
        logical :: graph_bfs
        type(List) :: queue
        integer :: cur
        type(ListNode), pointer :: iter
        graph_bfs = .false.
        nullify(queue%front)
        nullify(queue%back)
        call push(queue, src)
        do i = 1, g%nodes
            g%al(i)%visited = .false.
        end do
        do while (associated(queue%front))
            cur = queue%front%data
            call pop(queue)
            if (cur .eq. dest) then
                if (verbose) then
                    do while (cur .ne. src)
                        print *, cur, "<-"
                        cur = g%al(cur)%prec
                    end do
                    print *, src
                end if
                graph_bfs = .true.
                do while (associated(queue%front))
                    call pop(queue)
                end do
                return
            end if
            g%al(cur)%visited = .true.
            iter => g%al(cur)%idx%front
            do while (associated(iter))
                if (.not. g%al(iter%data)%visited) then
                    call push(queue, iter%data)
                    g%al(iter%data)%prec = cur
                end if
                iter => iter%next
            end do
        end do
        graph_bfs = .false.
        do while (associated(queue%front))
            call pop(queue)
        end do
    end function
end module
