#include "mpii.h"

PUBLIC int MPI_Ssend_init (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
   check_comm (comm);
   check_dest_rank (dest, comm);
   check_datatype (datatype, comm);

   request->active = 0;
   request->persistent = 1;
   request->type = MPII_REQUEST_SSEND;
   request->comm = comm;
   request->buf = buf;
   request->count = count;
   request->datatype = datatype;
   request->srcdest = dest;
   request->tag = tag;

   return MPI_SUCCESS;
}

