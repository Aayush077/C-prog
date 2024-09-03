 while (1)
    {
          printf("\nMENU\n1.INSERT AT ANY POSITION\n2.INSERT AT FIRST\n3.INSERT AT LAST\n4.Display\n5.Exit\nEnter Choice: ");
             scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the index and element to insert: ");
                scanf("%d %d",&index,&x);
                insert_linked(first,index,x);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_first(first,x);
                display_LinkedList(first);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_last(first,x);
                display_LinkedList(first);
                break;

            case 4:
                display_LinkedList(first);
                break;

            case 5:
            exit(0);

            default:
                printf("Invalid!!");
        }
    }